#ifndef GOOMBA_H
#define GOOMBA_H

#include "rsdl.hpp"
#include "blockSize.h"
#include <array>
#include <string>
#include "Gravity.h"

#define GOOMBA_SPEED 3
#define DEAD_ANIMATION 10


#define GOOMBA_WALK_1 "assets/sprites/enemies/little_goomba/walking-1.png"
#define GOOMBA_WALK_2 "assets/sprites/enemies/little_goomba/walking-2.png"
#define GOOMBA_DEAD "assets/sprites/enemies/little_goomba/dead.png"

const std::array<std::string, 2> GOOMBA_WALK_PNG {
    GOOMBA_WALK_1,
    GOOMBA_WALK_2
};

class LittleGoomba {
public:
    LittleGoomba(Point _position);
    void draw(Window* win, int winOffset, int screenWidth, int step);
    void update();
    int getVx();
    int getVy();
    Rectangle* getPositionPointer();
    bool* getDownCollisionPointer();
    void setVy(int _vy);
    void setVx(int _vx);
    void die();
    bool isDead();

private:
    void checkAppeared(int winOffset, int screenWidth);

    int vx;
    int vy;
    int ay;
    int frameDelay;
    Rectangle position;
    bool collidesDown;
    bool appeared;
    bool dead;
    int deadAnimation;
};

#endif