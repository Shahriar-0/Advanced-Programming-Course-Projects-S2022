#include "Mushroom.h"

Mushroom::Mushroom(Rectangle _position, char _type): position(_position), type(_type) {
    eaten = false;
    collidesDown = true;
    vx = MUSHROOM_SPEED;
    vy = 0;
    ay = GRAVITY / 4;   
}

void Mushroom::draw(Window* win, int winOffset) {
    if(!eaten) {
        win->draw_img(MUSHROOM_PNG[isItHealth()],
            Rectangle(position.x - winOffset, position.y,
            BLOCK_SIZE, BLOCK_SIZE)
        );
    }
}

void Mushroom::update() {
    if(!eaten) {
        position.x += vx;
        position.y += vy;
        if (!collidesDown)
            vy += ay;
    }
}

int Mushroom::getVx() {
    return vx;
}

int Mushroom::getVy() {
    return vy;
}

void Mushroom::setVx(int _vx) {
    vx = _vx;
}

void Mushroom::setVy(int _vy) {
    vy = _vy;
}

Rectangle* Mushroom::getPositionPointer() {
    return &position;
}

bool* Mushroom::getDownCollisionPointer() {
    return &collidesDown;
}

bool Mushroom::isEaten() {
    return eaten;
}

void Mushroom::beEaten() {
    eaten = true;
}

bool Mushroom::isItHealth() {
    if (type == HEALTH_MUSHROOM)
        return true;
    return false;
}

char Mushroom::getType() {
    return type;
}