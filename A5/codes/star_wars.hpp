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
#define BACKGROUND_ADDRESS "./assets/pictures/background/galaxy.jpeg"
#define FONT_ADDRESS "./assets/fonts/Starjedi.ttf"
constexpr char EMPRY_SYMBOL = '.';
constexpr char STATIONARY_ENEMY_SYMBOL = 'S';
constexpr char MOVING_ENEMY_SYMBOL = 'M';
constexpr char HOSTAGE_SYMBOL = 'H';
enum GameMode {RUNNING, WON, LOST};
typedef std::vector<std::string> singleMap;

class StarWars {
public:
    StarWars(std::string, Window*);
    ~StarWars();
    void read_file(std::string);
    void draw_background();
    void run();
    int read_sizes_of_map(std::ifstream&);
private:
    void process_events();
    void update_frame();
    void convert_map_to_positions(singleMap);
    void initialise();
    void check_for_end_round();
    void check_for_end_game();
    AudioPlayer musicPlayer;
    Window* win;
    Enemies enemies;
    SpaceShip spaceship;
    Hostage hostage;
    std::vector<singleMap> maps;
    GameMode gameMode;
    int totalHeight, totalWidth;
    int blockHeight, blockWidth;
    int level;
};

#endif 