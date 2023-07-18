#include <iostream>
#include <vector>

#define ROCK '#'
#define BAMBOO '*'
#define EMPTY '.'
#define NO_PATH -1

enum Direction { RIGHT,
                 LEFT,
                 UP,
                 DOWN };
                 
enum Coordinate_status { NOT_SEEN,
                         SEEN };

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

int length_of_shortest_path(std::vector<std::vector<Coordinate>>&);
int find_shortest_path(std::vector<std::vector<Coordinate>>, Direction, Point, int = 0);
int changing_direction(std::vector<std::vector<Coordinate>>, Direction, Point, int);
void mark_position(std::vector<std::vector<Coordinate>>&, const Point, Direction);
int check_result(int, int);
bool in_loop(const std::vector<std::vector<Coordinate>>&, Direction, Point);
bool hit_edge(Point, int, int);
Point generate_previous_coordinate(Point, Direction);
Point generate_new_coordinate(Point, Direction);
std::vector<std::vector<Coordinate>> get_input(void);

int main(void) {
    std::vector<std::vector<Coordinate>> map = get_input();
    int minLength = length_of_shortest_path(map);
    std::cout << ((minLength == NO_PATH) ? "No path found" : std::to_string(minLength)) << std::endl;
}

std::vector<std::vector<Coordinate>> get_input() {
    std::vector<std::vector<Coordinate>> map;
    int index = 0;
    std::string line;
    while (std::cin >> line) {
        map.resize(index + 1);
        map[index].resize(line.length());
        for (int i = 0; i < line.length(); i++) {
            map[index][i].data = line[i];
            map[index][i].down = map[index][i].up = map[index][i].right = map[index][i].left = NOT_SEEN;
        }
        index++;
    }
    return map;
}

Point generate_new_coordinate(Point position, Direction direction) {
    position.y += (direction == RIGHT) - (direction == LEFT);
    position.x += (direction == DOWN) - (direction == UP);
    return position;
}

Point generate_previous_coordinate(Point position, Direction direction) {
    position.y -= (direction == RIGHT) - (direction == LEFT);
    position.x -= (direction == DOWN) - (direction == UP);
    return position;
}

bool hit_edge(Point position, int numOfRows, int numOfColumns) {
    return (position.x == numOfRows) || (position.x == -1) ||
           (position.y == numOfColumns) || (position.y == -1);
}

bool in_loop(const std::vector<std::vector<Coordinate>>& map, Direction direction, Point position) {
    switch (direction) {
        case RIGHT:
            return map[position.x][position.y].right;
        case LEFT:
            return map[position.x][position.y].left;
        case UP:
            return map[position.x][position.y].up;
        case DOWN:
            return map[position.x][position.y].down;
    }
    throw "Invalid direction";
}

void mark_position(std::vector<std::vector<Coordinate>>& map, const Point position, Direction direction) {
    switch (direction) {
        case RIGHT:
            map[position.x][position.y].right = SEEN;
            break;
        case LEFT:
            map[position.x][position.y].left = SEEN;
            break;
        case UP:
            map[position.x][position.y].up = SEEN;
            break;
        case DOWN:
            map[position.x][position.y].down = SEEN;
            break;
    }
}

int changing_direction(std::vector<std::vector<Coordinate>> map, Direction direction, Point position, int length) {
    position = generate_previous_coordinate(position, direction);
    int minLengthFirst, minLengthSecond;
    if (direction == RIGHT || direction == LEFT) {
        minLengthFirst = find_shortest_path(map, UP, position, length - 1);
        minLengthSecond = find_shortest_path(map, DOWN, position, length - 1);
    } else {
        minLengthFirst = find_shortest_path(map, LEFT, position, length - 1);
        minLengthSecond = find_shortest_path(map, RIGHT, position, length - 1);
    }

    return check_result(minLengthFirst, minLengthSecond);
}

int find_shortest_path(std::vector<std::vector<Coordinate>> map, Direction direction, Point position, int length) {
    bool hitEdge = false, inLoop = false;

    do {
        inLoop = in_loop(map, direction, position);
        mark_position(map, position, direction);
        position = generate_new_coordinate(position, direction);
        hitEdge = hit_edge(position, map.size(), map[0].size());
        length++;
    } while (!hitEdge && !inLoop && map[position.x][position.y].data == EMPTY);

    if (inLoop)
        return NO_PATH;

    if (hitEdge || map[position.x][position.y].data == ROCK)
        return changing_direction(map, direction, position, length);

    if (map[position.x][position.y].data == BAMBOO)
        return length;
    
    return NO_PATH;
}

int length_of_shortest_path(std::vector<std::vector<Coordinate>>& map) {
    constexpr Point PANDA_POSITION = {0, 0};
    Direction FIRST_INITIAL_DIRECTION = RIGHT, SECOND_INITIAL_DIRECTION = DOWN;
    int minLengthFirst = find_shortest_path(map, FIRST_INITIAL_DIRECTION, PANDA_POSITION);
    int minLengthSecond = find_shortest_path(map, SECOND_INITIAL_DIRECTION, PANDA_POSITION);
    return check_result(minLengthFirst, minLengthSecond);
}

int check_result(int first, int second) {
    if (first == NO_PATH && second == NO_PATH)
        return NO_PATH;
    if (first == NO_PATH)
        return second;
    if (second == NO_PATH)
        return first;
    return std::min(first, second);
}
