#ifndef __MOVING_ENEMY_HPP__
#define __MOVING_ENEMY_HPP__
#include "bullet.hpp"
#include "stationary_enemy.hpp"

#define MOVING_ENEMY_PIC "./assets/pictures/spaceships/moving_enemy.jpeg"
constexpr int HORIZONTEL_SPEED = 10;

class MovingEnemy : public StationaryEnemy {
public:
    MovingEnemy(Point, Window*);
    void put_in_frame();
    virtual void draw();
    virtual void update();
};

#endif