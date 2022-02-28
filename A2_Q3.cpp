#include <iostream>
#include <vector>

using namespace std;

#define BIG_NUMBER 1e8
#define ROCK '#'
#define BAMBOO '*'
#define EMPTY '.'

enum Edge_status {NOT_HIT, RIGHT_EDGE, LEFT_EDGE, UPPER_EDGE, BELOW_EDGE};
enum Direction {RIGHT, LEFT, UP, DOWN};
enum Coordinate_status {NOT_SEEN, SEEN};

struct Coordinate {
    char data;
    Coordinate_status right;
    Coordinate_status left;
    Coordinate_status up;
    Coordinate_status down;
};

struct Point {
    int x;
    int y;
};

void getting_input(vector<vector<Coordinate>>& map) {
    int index = 0;
    string line;
    while (cin >> line) {
        map.resize(index + 1);
        map[index].resize(line.length());
        for (int i = 0; i < line.length(); i++) {
            map[index][i].data = line[i];
            map[index][i].down = map[index][i].up = map[index][i].right = map[index][i].left = NOT_SEEN;
        }
        index++;
    }
}

Point generate_new_coordinate(Point position, Direction direction) {
    position.y += (direction == RIGHT) - (direction == LEFT);
    position.x += (direction == DOWN) - (direction == UP);
    return position;
}

Edge_status hit_edge(Point position, int numOfRows, int numOFColumns) {
    if (position.x == numOfRows)
        return BELOW_EDGE;
    if (position.x == -1)
        return UPPER_EDGE;
    if (position.y == numOFColumns)
        return RIGHT_EDGE;
    if (position.y == -1)
        return LEFT_EDGE;
    return NOT_HIT;
}

bool in_loop(const vector<vector<Coordinate>>& map, Direction direction, Point position) {
    switch (direction) {
            case RIGHT: return map[position.x][position.y].right;
            case LEFT: return map[position.x][position.y].left;
            case UP: return map[position.x][position.y].up;
            case DOWN: return map[position.x][position.y].down;
    }
}

int find_shortest_path(vector<vector<Coordinate>> map, Direction direction, Point position, int length = 0) {
    Edge_status hittedEdge;
    bool inLoop;
    do {
        //we go ahead till we hit rock or edge or we stuck in a loop
        switch (direction) {
            case RIGHT: map[position.x][position.y].right = SEEN; break;
            case LEFT: map[position.x][position.y].left = SEEN; break;
            case UP: map[position.x][position.y].up = SEEN; break;
            case DOWN: map[position.x][position.y].down = SEEN; break;
        }
        
        position = generate_new_coordinate(position, direction);
        length++;
        hittedEdge = hit_edge(position, map.size(), map[0].size());
        inLoop = in_loop(map, direction, position);
    } while (!hittedEdge && map[position.x][position.y].data == EMPTY && !inLoop);

    if (hittedEdge) {
        //go to previous position
        length--;
        position.y -= (direction == RIGHT) - (direction == LEFT);
        position.x -= (direction == DOWN) - (direction == UP);
        //check the other two
        if (hittedEdge == RIGHT_EDGE || hittedEdge == LEFT_EDGE) 
            return min(find_shortest_path(map, UP, position, length), find_shortest_path(map, DOWN, position, length));
        
        else 
            return min(find_shortest_path(map, LEFT, position, length), find_shortest_path(map, RIGHT, position, length));
    }

    if (inLoop) 
        //we are stuck in a loop so we
        //just return random big number
        return BIG_NUMBER;
    if (map[position.x][position.y].data == BAMBOO)
        //finally found
        return length;

    if (map[position.x][position.y].data == ROCK) {
        //go to previous position
        length--;
        position.y -= (direction == RIGHT) - (direction == LEFT);
        position.x -= (direction == DOWN) - (direction == UP);
        //check the other two
        if (direction == RIGHT || direction == LEFT)
            return min(find_shortest_path(map, UP, position, length), find_shortest_path(map, DOWN, position, length));
        
        else 
            return min(find_shortest_path(map, LEFT, position, length), find_shortest_path(map, RIGHT, position, length));
    }
}

int main(void) {
    const Point PANDA_POSITION = {0, 0};
    Direction FIRST_INITIAL_DIRECTION = RIGHT, SECOND_INITIAL_DIRECTION = DOWN;
    vector<vector<Coordinate>> map;
    getting_input(map);
    cout << endl;
    cout << min(find_shortest_path(map, FIRST_INITIAL_DIRECTION, PANDA_POSITION),
         find_shortest_path(map, SECOND_INITIAL_DIRECTION, PANDA_POSITION)) << endl;
}
