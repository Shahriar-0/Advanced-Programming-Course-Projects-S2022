#ifndef __STAR_WARS_HPP__
#define __STAR_WARS_HPP__
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <fstream>
#include "spaceship.hpp"
#include "enemies.hpp"
#include "hostage.hpp"
#include "audio.hpp"

#define MAP_SPLITTER "-----"
#define BACKGROUND_ADDRESS "assets/pictures/background/galaxy.jpeg"

typedef std::vector<std::string> gameMap;

class StarWars {
public:
    StarWars(std::string, Window*);
    ~StarWars();
    void read_file(std::string);
    void draw_background();
    //void run();
private:
    AudioPlayer musicPlayer;
    Window* win;
    //void initialise();
    std::vector<gameMap> maps;
    int totalHeight, totalWidth;
};

#endif 