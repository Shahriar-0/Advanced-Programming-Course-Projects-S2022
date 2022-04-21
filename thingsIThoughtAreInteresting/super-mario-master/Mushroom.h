#ifndef MUSHROOM_H
#define MUSHROOM_H

#include "rsdl.hpp"
#include "blockSize.h"
#include "string"
#include "Gravity.h"
#include "array"

#define RED_MUSHROOM_PNG "assets/sprites/objects/mushroom/red.png"
#define HEALTH_MUSHROOM_PNG "assets/sprites/objects/mushroom/health.png"

#define RED_MUSHROOM 'm'
#define HEALTH_MUSHROOM 'h'

const std::array<std::string, 2> MUSHROOM_PNG {
    RED_MUSHROOM_PNG,
    HEALTH_MUSHROOM_PNG
};

#define MUSHROOM_SPEED 3

class Mushroom {
public:
    Mushroom(Rectangle _position, char _type);
    void draw(Window* win, int winOfsset);
    void update();
    int getVx();
    int getVy();
    Rectangle* getPositionPointer();
    bool* getDownCollisionPointer();
    void setVy(int _vy);
    void setVx(int _vx);
    bool isEaten();
    void beEaten();
    char getType();

private:
    bool isItHealth();

    char type;
    int vx;
    int vy;
    int ay;
    int frameDelay;
    Rectangle position;
    bool collidesDown;
    bool eaten;
};

#endif