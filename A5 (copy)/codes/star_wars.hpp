#ifndef __STAR_WARS_HPP__
#define __STAR_WARS_HPP__
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <fstream>
#include "bullet.hpp"
#include "my_space_ship.hpp"
#include "audio.hpp"
#include "enemies.hpp"
#include "hostage.hpp"

#define MAP_SPLITTER "-----"
#define BACKGROUND_ADDRESS "./assets/pictures/background/galaxy.jpeg"
#define FONT_ADDRESS "./assets/fonts/Starjedi.ttf"
constexpr char EMPTY_SYMBOL = '.';
constexpr char STATIONARY_ENEMY_SYMBOL = 'S';
constexpr char MOVING_ENEMY_SYMBOL = 'M';
constexpr char HOSTAGE_SYMBOL = 'H';
enum GameMode {RUNNING, WON, LOST};

typedef std::vector<std::string> singleMap;

class StarWars {
public:
    StarWars(std::string, Window*);
    ~StarWars();
    void run();
private:
    void read_file(std::string);
    int read_sizes_of_map(std::ifstream&);
    void draw_background();
    void update_bullets();
    void update_hostages();
    void process_events();
    void space_ship_shoot();
    void update_frame();
    void convert_map_to_positions(singleMap);
    void initialise();
    void check_for_end_round();
    void check_for_end_game();
    void erase_extra_bullets();
    AudioPlayer musicPlayer;
    Window* win;
    Enemies enemies;
    MySpaceShip mySpaceShip;
    std::vector<Hostage> hostages;
    std::vector<singleMap> maps;
    std::vector<Bullet> bullets;
    GameMode gameMode;
    int blockHeight, blockWidth;
    int level;
};

#endif 