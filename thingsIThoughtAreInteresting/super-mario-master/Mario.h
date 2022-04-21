#ifndef MARIO_H
#define MARIO_H

#include "rsdl.hpp"
#include "blockSize.h"
#include <array>
#include <string>
#include "Gravity.h"
#include "Game.h"
#include "Mushroom.h"
#include "MarioDefines.h"
#include "Sound.h"

class Game;

class Mario {
public:
    Mario(Point pos, Game* _game);
    void draw(Window* win, int winOffset, int step);
    void handleKeyPress(char key);
    void handleKeyRelease(char key);
    void update();
    Point getPosition();
    Rectangle* getPositionPointer();
    int getVx();
    int getVy();
    void setVx(int _vx);
    void setVy(int _vy);
    bool* getDownCollisionPointer();
    void die();
    int getVictoryStatus();
    bool isAlive();
    void eatMushroom(char type);
    void addCoin();
    bool isMarioNormal();
    void won();
    void addSound(Sound* _sound);

private:
    void drawHeader(Window* win);
    bool isWalking();
    bool isSliding();
    void revive();
    void dPress();
    void aPress();
    bool shouldRevive();
    void updateVx();
    bool hasFallenDown();
    void preventGoingLeft();

    Sound* sound;
    Game* game;
    bool big;
    Rectangle position;
    Rectangle initialPosition;
    int livesCount;
    int coinsCount;
    int vx;
    int vy;
    int ay;
    int ax;
    bool faceRight;
    bool collidesDown;
    bool aReleased;
    bool dReleased;
    int dead;
    int frameDelay;
    int invincible;
};

#endif
