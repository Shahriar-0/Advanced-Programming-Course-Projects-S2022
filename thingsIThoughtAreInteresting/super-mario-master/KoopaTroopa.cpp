#include "KoopaTroopa.h"

KoopaTroopa::KoopaTroopa(Point _position):
    position(_position, BLOCK_SIZE, BLOCK_SIZE) {
        appeared = false;
        vx = vy = frameDelay = deadAnimitation = 0;
        ay = GRAVITY / 4;
        collidesDown = true;
        dead = killedByKoopa = false;
    }

void KoopaTroopa::draw(Window* win, int winOffset, int screenWidth, int step) {
    if (step % 4 == 0)
        frameDelay++;
    if (!appeared)
        checkAppeared(winOffset ,screenWidth);
    if (killedByKoopa) {
        if(deadAnimitation--)
            win->draw_img(KOOPA_DEAD,
                Rectangle(position.x - winOffset, position.y,
                BLOCK_SIZE, BLOCK_SIZE)
             );
    }
    else if (dead)  
        win->draw_img(KOOPA_DEAD,
            Rectangle(position.x - winOffset, position.y,
            BLOCK_SIZE, BLOCK_SIZE)
        );
    else {
        if (vx > 0) {
            win->draw_img(KOOPA_R[frameDelay % 2],
                Rectangle(position.x - winOffset, position.y,
                BLOCK_SIZE, BLOCK_SIZE)
            );
        }
        else if (vx < 0) {
            win->draw_img(KOOPA_L[frameDelay % 2],
                Rectangle(position.x - winOffset, position.y,
                BLOCK_SIZE, BLOCK_SIZE)
            );
        }
    }
}

void KoopaTroopa::update() {
    if (killedByKoopa && !deadAnimitation)
        position.x = -100;
    if(appeared) {
        position.x += vx;
        position.y += vy;
        if (!collidesDown) 
            vy += ay;
    }
}

void KoopaTroopa::checkAppeared(int winOffset, int screenWidth) {
    if (position.x - winOffset < screenWidth) {
        appeared = true;
        vx = -KOOPA_SPEED;
    }
}

int KoopaTroopa::getVx() {
    return vx;
}

int KoopaTroopa::getVy() {
    return vy;
}

Rectangle* KoopaTroopa::getPositionPointer() {
    return &position;
}

bool* KoopaTroopa::getDownCollisionPointer() {
    return &collidesDown;
}

void KoopaTroopa::setVx(int _vx) {
    vx = _vx;
}

void KoopaTroopa::setVy(int _vy) {
    vy = _vy;
}

void KoopaTroopa::die() {
    dead = true;
    vx = KOOPA_DEAD_SPEED;
}

bool KoopaTroopa::isDead() {
    return dead;
}

void KoopaTroopa::dieByKoopa() {
    dead = true;
    killedByKoopa = true;
    deadAnimitation = KOOPA_DEAD_ANIMATION;
}