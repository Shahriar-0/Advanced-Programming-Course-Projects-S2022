#ifndef __STAR_WARS_HPP__
#define __STAR_WARS_HPP__
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <fstream>
#include "spaceship.hpp"
#include "enemies.hpp"
#include "hostage.hpp"
#include "audio.hpp"

#define MAP_SPLITTER "-----"
#define BACKGROUND_ADDRESS "assets/pictures/background/galaxy.jpeg"
constexpr char EMPRY_SYMBOL = '.';
constexpr char STATIONARY_ENEMY_SYMBOL = 'S';
constexpr char MOVING_ENEMY_SYMBOL = 'M';
constexpr char HOSTAGE_SYMBOL = 'H';

typedef std::vector<std::string> singleMap;

class StarWars {
public:
    StarWars(std::string, Window*);
    ~StarWars();
    void read_file(std::string);
    void draw_background();
    void run();
    int read_sizes_of_map(ifstream&);
private:
    void convert_map_to_positions(singleMap);
    void initialise();
    AudioPlayer musicPlayer;
    Window* win;
    Enemies enemies;
    SpaceShip spaceship;
    Hostage hostage;
    std::vector<singleMap> maps;
    int totalHeight, totalWidth;
    int blockHeight, blockWidth;
    int frameCounter;
    int level;
};

#endif 