#ifndef __MOVING_ENEMY_HPP__
#define __MOVING_ENEMY_HPP__
#include "bullet.hpp"
#include "stationary_enemy.hpp"

#define MOVING_ENEMY_PIC "./assets/pictures/spaceships/moving_enemy.png"
constexpr int HORIZONTEL_SPEED = 6;

class MovingEnemy : public StationaryEnemy {
public:
    MovingEnemy(Point, Window*, int, int);
    void put_in_frame();
    virtual void draw();
    virtual void update();
};

#endif