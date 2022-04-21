#ifndef KOOPA_H
#define KOOPA_H

#include "rsdl.hpp"
#include "blockSize.h"
#include <string>
#include <array>
#include "Gravity.h"

#define KOOPA_SPEED 3
#define KOOPA_DEAD_SPEED 8
#define KOOPA_DEAD_ANIMATION 5

#define KOOPA_WALKING_R_1 "assets/sprites/enemies/koopa_troopa/walking-right-1.png"
#define KOOPA_WALKING_R_2 "assets/sprites/enemies/koopa_troopa/walking-right-2.png"
#define KOOPA_WALKING_L_1 "assets/sprites/enemies/koopa_troopa/walking-left-1.png"
#define KOOPA_WALKING_L_2 "assets/sprites/enemies/koopa_troopa/walking-left-2.png"
#define KOOPA_DEAD "assets/sprites/enemies/koopa_troopa/dead.png"

const std::array<std::string, 2> KOOPA_R = {
    KOOPA_WALKING_R_1,
    KOOPA_WALKING_R_2
};

const std::array<std::string, 2> KOOPA_L = {
    KOOPA_WALKING_L_1,
    KOOPA_WALKING_L_2
};

class KoopaTroopa {
public:
    KoopaTroopa(Point _position);
    void draw(Window* win, int winOffset, int screenWidth, int step);
    void update();
    int getVx();
    int getVy();
    Rectangle* getPositionPointer();
    bool* getDownCollisionPointer();
    void setVy(int _vy);
    void setVx(int _vx);
    void die();
    void dieByKoopa();
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
    int deadAnimitation;
    bool killedByKoopa;
};

#endif