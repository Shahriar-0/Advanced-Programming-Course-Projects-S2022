#ifndef __STAR_WARS_HPP__
#define __STAR_WARS_HPP__
#include <iostream>
#include <string>
#include <cstring>
// #include "enemy_bullet.hpp"
// #include "my_bullet.hpp"
// #include "moving_enemies.hpp"
// #include "moving_enemy.hpp"
// #include "my_bullet.hpp"
// #include "spaceship.hpp"
// #include "rsdl.hpp"
// #include "stationary_enemies.hpp"
// #include "stationary_enemy.hpp"
#include "audio.hpp"

class StarWars {
public:
    StarWars(std::string, Window*);
    //void run();
private:
    AudioPlayer musicPlayer;
    Window* win;
    //void initialise();

};

#endif 