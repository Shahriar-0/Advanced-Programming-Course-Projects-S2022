#include "Mario.h"
#include <iostream>
using namespace std;


Mario::Mario(Point pos, Game* _game): game(_game),
        position(pos, BLOCK_SIZE, BLOCK_SIZE), initialPosition(position) {
    coinsCount = vx = vy = ax = frameDelay = dead = invincible = 0;
    livesCount = 3;
    ay = GRAVITY;
    aReleased = dReleased = collidesDown = faceRight = true;
    big = false;
}

void Mario::draw(Window* win, int winOffset, int step) {
    drawHeader(win);
    if (step % 2 == 0)
        frameDelay++;
    if (dead != 0) {
        win->draw_img(DEAD_PNG[isMarioNormal()],
            Rectangle(position.x - winOffset, position.y,
            position.w, position.h)
        );
        dead--;
    }
    else if (!collidesDown) {
        win->draw_img(JUMP_PNG[isMarioNormal()][faceRight],
            Rectangle(position.x - winOffset, position.y,
            position.w, position.h)
        );
    }
    else if(isSliding()) {
        win->draw_img(SLIDING_PNG[isMarioNormal()][faceRight],
            Rectangle(position.x - winOffset, position.y,
            position.w, position.h)
        ); 
    }
    else if(isWalking()) {
        win->draw_img(WALK_PNG[isMarioNormal()][faceRight][frameDelay % 3],
            Rectangle(position.x - winOffset, position.y,
            position.w, position.h)
        );
    } 
    else {
        win->draw_img(STAND_PNG[isMarioNormal()][faceRight],
            Rectangle(position.x - winOffset, position.y,
            position.w, position.h)
        );
    }
}

bool Mario::isWalking() {
    if (vx != 0)
        return true;
    return false;
}

bool Mario::isSliding() {
    return ((!aReleased && vx > 0) || (!dReleased && vx < 0));
}

bool Mario::isMarioNormal() {
    return !big;
}

void Mario::drawHeader(Window* win) {
    win->show_text(COIN, HEADER_TEXT_POINT, WHITE, FONT);
    win->show_text(to_string(coinsCount), HEADER_COUNT_POINT, WHITE, FONT);
    win->show_text(LIVES, Point(win->get_width() - 100, HEADER_TEXT_POINT.y), WHITE, FONT);
    win->show_text(to_string(livesCount), Point(win->get_width() - 75, HEADER_COUNT_POINT.y), WHITE, FONT);
}

void Mario::handleKeyPress(char key) {
    switch (key) {
        case 'd':
            dPress();
            break;
        case 'a':
            aPress();
            break;
        case 'w':
            if (collidesDown) {
                vy = -JUMP_SPEED;
                collidesDown = false;
                sound->playJump(big);
            }
            break;
    }
}

void Mario::dPress() {
    faceRight = true;
    dReleased = false;
    ax = X_ACCELERATION;
}

void Mario::aPress() {
    faceRight = false;
    aReleased = false;
    ax = -X_ACCELERATION;
}

void Mario::handleKeyRelease(char key) {
    switch (key) {
        case 'd':
            dReleased = true;
            ax = -X_ACCELERATION;
            break;
        case 'a':
            aReleased = true;
            ax = X_ACCELERATION;
            break;
    }
}

void Mario::update(){
    if (invincible)
        invincible--;
    if (!dead) {
        position.x += vx;
        position.y += vy;
        if (!collidesDown)
            vy += ay;
        updateVx();
        preventGoingLeft();
        if (hasFallenDown())
            die();
    }
    else {
        position.y += 5;
    }
    if (shouldRevive()) {
        delay(1000);
        revive();
    }
}

void Mario::updateVx() {
    if(aReleased && dReleased) {
        if (vx != 0) {
            if (vx * ax > 0)
                vx -= ax;
            else
                vx += ax;
        }
    } else {
        if ((ax > 0 && vx < X_SPEED)
        || (ax < 0 && vx > -X_SPEED))
            vx += ax;
    }
}

void Mario::die() {
    if (invincible)
        return;
    if (big) {
        position = Rectangle(position.x, position.y - BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE);
        big = false;
        invincible = INVINCIBLE;
    }
    else {
        livesCount--;
        if (livesCount != 0) {
            sound->pauseBackgroudnMusic();
            sound->playDeathEffect();
            dead = DEAD_HAS_LIVES;
        }
        else 
            game->lose();
    }
}

Point Mario::getPosition() {
    return Point(position.x, position.y);
}

Rectangle* Mario::getPositionPointer() {
    return &position;
}

int Mario::getVx() {
    return vx;
}

int Mario::getVy() {
    return vy;
}

void Mario::setVx(int _vx) {
    vx = _vx;
}

void Mario::setVy(int _vy) {
    vy = _vy;
}

bool* Mario::getDownCollisionPointer() {
    return &collidesDown;
}

void Mario::revive() {
    sound->continueBackgroundMusic();
    position.x = initialPosition.x;
    position.y = initialPosition.y;
    dead = 0;
    game->resetOffset();
}

bool Mario::hasFallenDown() {
    if (position.y > game->getWinHeight()) {
        return true;
    }
    return false;
}

bool Mario::shouldRevive() {
    if (dead == 1)
        return true;
    return false;
}

bool Mario::isAlive() {
    if (!dead)
        return true;
    return false;
}

void Mario::addCoin() {
    sound->playCoin();
    coinsCount++;
}

void Mario::eatMushroom(char type) {
    sound->playEatMushroomEffect();
    if (type == RED_MUSHROOM) {
        if (!big) {
            big = true;
            position.y -= BLOCK_SIZE;
            position.h += BLOCK_SIZE;
        }
    }
    else 
        livesCount++;
}

void Mario::preventGoingLeft() {
    if (position.x < game->getWinOffset())
        position.x = game->getWinOffset();
}

void Mario::won() {
    game->win();
}

void Mario::addSound(Sound* _sound) {
    sound = _sound;
}