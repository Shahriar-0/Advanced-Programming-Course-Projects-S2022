#ifndef __MOVING_ENEMY_HPP__
#define __MOVING_ENEMY_HPP__
#include <vector>
#include "bullet.hpp"
#include "stationary_enemy.hpp"
#define MOVING_ENEMY_PIC "./assets/pictures/spaceships/moving_enemy.jpeg"
const int MOVING_RIGHT_SPEED = 10;
const int MOVING_LEFT_SPEED = 10;

class MovingEnemy : public StationaryEnemy {
public:
    MovingEnemy(Point, int, int);
    virtual void update(Window*); 
    void move();
private:
    void draw(Window*);
    int frameCounter;
    int vx;
    Point topLeft;
    std::vector<Bullet> bullets;
    bool exists;
    int blockWidth, blockHeight;
};

#endif