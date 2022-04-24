#ifndef __SPACESHIP_HPP__
#define __SPACESHIP_HPP__
#include "my_bullet.hpp"
#include "moving_enemies.hpp"
#include "stationary_enemies.hpp"
#include "audio.hpp"
#include <vector>
#define MY_SPACESHIP_PIC "./assets/pictures/spaceships/my_spaceship.png"

class SpaceShip {
public:
    SpaceShip(Window*, AudioPlayer*, int, int);
private:
    Window* win;
    AudioPlayer* musicPlayerptr;
    MovingEnemies* listOfMovingEnemies;
    StationaryEnemies* listOfStationaryEnemies;
    Hostage* hostage;
    Point center;
    std::vector<MyBullet> myBullets;
    int vy, vx;
    bool exists;
    int blockWidth, blockHeight;
};

#endif