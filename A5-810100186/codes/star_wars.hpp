#ifndef __STAR_WARS_HPP__
#define __STAR_WARS_HPP__
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <fstream>
// #include "enemy_bullet.hpp"
// #include "my_bullet.hpp"
// #include "moving_enemies.hpp"
// #include "moving_enemy.hpp"
// #include "my_bullet.hpp"
// #include "spaceship.hpp"s
// #include "rsdl.hpp"
// #include "stationary_enemies.hpp"
// #include "stationary_enemy.hpp"
#include "audio.hpp"

#define MAP_SPLITTER "-----"
#define BACKGROUND_ADDRESS "assets/pictures/background/galaxy.jpeg"

class StarWars {
public:
    StarWars(std::string, Window*);
    void read_file(std::string);
    void draw_background();
    //void run();
private:
    AudioPlayer musicPlayer;
    Window* win;
    //void initialise();
    std::vector<std::vector<std::string>> maps;
    int totalHeight, totalWidth;
};

#endif 