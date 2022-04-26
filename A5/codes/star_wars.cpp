#include "star_wars.hpp"
using namespace std;

StarWars::StarWars(string filename, Window* _win) : 
    musicPlayer(_win), enemies(_win), spaceship(_win){
    win = _win;
    totalHeight = _win->get_height();
    totalWidth = _win->get_width();
    frameCounter = 0;
    level = 1;
    musicPlayer.play_theme();
    read_file(filename);
    draw_background();      //todo: delete this line
    win->update_screen();   //todo: and this one
    delay(10000);
}

void StarWars::initialise() {
    gameMap currentMap = maps[level - 1];
}

void StarWars::read_file(string filename) {
    ifstream fileStream (filename);
    int numOfMaps;
    fileStream >> numOfMaps;
    int numOfCellsHeight, numOfCellsWidth;
    fileStream >> numOfCellsHeight >> numOfCellsWidth;
    blockWidth = totalHeight / numOfCellsHeight;
    blockHeight = totalWidth / numOfCellsWidth;
    enemies.set_window_size(blockWidth, blockHeight);
    vector<gameMap> _maps;
    gameMap currentMap;
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
    maps = _maps;
    fileStream.close();
}

void StarWars::draw_background() {
    win->draw_img(BACKGROUND_ADDRESS);
}


StarWars::~StarWars() {
    delete win;
}