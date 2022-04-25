#include "star_wars.hpp"
using namespace std;

void StarWars::read_file(string filename) {
    ifstream fileStream (filename);
    int numOfMaps;
    fileStream >> numOfMaps;
    fileStream >> totalHeight >> totalWidth;
    vector<gameMap> _maps;
    gameMap currentMap;
    while (numOfMaps--) {
        currentMap.clear();
        string line;
        do {
            fileStream >> line;
            currentMap.push_back(line);
        } while (line != MAP_SPLITTER);
        currentMap.pop_back(); //to get rid of the extra splitter

        _maps.push_back(currentMap);
    }
    maps = _maps;
    fileStream.close();
}

void StarWars::draw_background() {
    win->draw_img(BACKGROUND_ADDRESS);
}

StarWars::StarWars(string filename, Window* _win) : musicPlayer(_win) {
    win = _win;
    musicPlayer.play_theme();
    read_file(filename);
    draw_background();      //todo: delete this line
    win->update_screen();   //todo: and this one
    delay(10000);
}

StarWars::~StarWars() {
    delete win;
}