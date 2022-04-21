#include "LittleGoomba.h"

LittleGoomba::LittleGoomba(Point _position):
        position(_position, BLOCK_SIZE, BLOCK_SIZE) {
    appeared = false;
    vx = vy = frameDelay = deadAnimation = 0;
    ay = GRAVITY / 4;
    collidesDown = true;
    dead = false;

}

void LittleGoomba::draw(Window* win, int winOffset, int screenWidth, int step) {
    if (step % 4 == 0)
        frameDelay++;
    if (!appeared)
        checkAppeared(winOffset ,screenWidth);
    else if(deadAnimation) {
        win->draw_img(GOOMBA_DEAD,
            Rectangle(position.x - winOffset, position.y,
            BLOCK_SIZE, BLOCK_SIZE)
        );
        deadAnimation--;
    }
    else if(!dead){
        win->draw_img(GOOMBA_WALK_PNG[frameDelay % 2],
            Rectangle(position.x - winOffset, position.y,
            BLOCK_SIZE, BLOCK_SIZE)
        );
    }
}

void LittleGoomba::update() {
    if(appeared && !dead) {
        position.x += vx;
        position.y += vy;
        if (!collidesDown)
            vy += ay;
    }
}

void LittleGoomba::checkAppeared(int winOffset, int screenWidth) {
    if (position.x - winOffset < screenWidth) {
        appeared = true;
        vx = -GOOMBA_SPEED;
    }
}

int LittleGoomba::getVx() {
    return vx;
}

int LittleGoomba::getVy() {
    return vy;
}

Rectangle* LittleGoomba::getPositionPointer() {
    return &position;
}

bool* LittleGoomba::getDownCollisionPointer() {
    return &collidesDown;
}

void LittleGoomba::setVy(int _vy) {
    vy = _vy;
}

void LittleGoomba::setVx(int _vx) {
    vx = _vx;
}

void LittleGoomba::die() {
    dead = true;
    deadAnimation = DEAD_ANIMATION;
}

bool LittleGoomba::isDead() {
    return dead;
}