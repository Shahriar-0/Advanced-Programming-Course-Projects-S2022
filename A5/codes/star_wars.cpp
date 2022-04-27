#include "star_wars.hpp"
using namespace std;

StarWars::StarWars(string filename, Window* _win) : 
    musicPlayer(_win), enemies(_win), spaceship(_win) {
    enemies.set_space_ship(&spaceship);
    enemies.set_music_player(&musicPlayer);
    win = _win;
    totalHeight = _win->get_height();
    totalWidth = _win->get_width();
    frameCounter = 0;
    level = 1;
    musicPlayer.play_theme();
    read_file(filename);
}

int StarWars::read_sizes_of_map(ifstream& fileStream) {
    int numOfMaps;
    fileStream >> numOfMaps;
    int numOfBlocksHeight, numOfBlocksWidth;
    fileStream >> numOfBlocksHeight >> numOfBlocksWidth;
    blockWidth = totalHeight / numOfBlocksHeight;
    blockHeight = totalWidth / numOfBlocksWidth;
    enemies.set_block_size(blockWidth, blockHeight);
    spaceship.set_block_size(blockWidth, blockHeight);
}

void StarWars::read_file(string filename) {
    ifstream fileStream (filename);
    int numOfMaps = read_sizes_of_map(fileStream);

    vector<singleMap> _maps;
    singleMap currentMap;
    while (numOfMaps--) {
        currentMap.clear();
        string line;
        do {
            fileStream >> line;
            currentMap.push_back(line);
        } while (line != MAP_SPLITTER);
        currentMap.pop_back(); //to get rid of the extra line which is splitter

        _maps.push_back(currentMap);
    }
    maps = _maps;   //this line ans the whole local maps is to avoid stack overflow
    fileStream.close();
}

void StarWars::initialise() {
    enemies.initialise();
    spaceship.initialise();
    singleMap currentMap = maps[level - 1];
    convert_map_to_positions(currentMap);
}

void StarWars::convert_map_to_positions(singleMap currentMap) {
    for (int i = 0; i < currentMap.size(); i++) {
        for (int j = 0; j < currentMap[0].size(); j++) {
            if (currentMap[i][j] == EMPRY_SYMBOL)
                continue;
            if (currentMap[i][j] == STATIONARY_ENEMY_SYMBOL)
                enemies.add_member(StationaryEnemy(Point(j * blockWidth, i * blockHeight), blockWidth, blockHeight));
            else if (currentMap[i][j] == MOVING_ENEMY_SYMBOL)
                enemies.add_member(MovingEnemy(Point(j * blockWidth, i * blockHeight), blockWidth, blockHeight));
            else if (currentMap[i][j] == HOSTAGE_SYMBOL)
                hostage.set_top_left(Point(j * blockWidth, i * blockHeight));
        }
    }
}

void StarWars::run() {

}

void StarWars::draw_background() { win->draw_img(BACKGROUND_ADDRESS); }
StarWars::~StarWars() { delete win; }