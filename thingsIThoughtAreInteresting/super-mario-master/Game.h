#ifndef GAME_H
#define GAME_H

#include "rsdl.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <vector>
#include "Map.h"
#include "CollisionHandler.h"
#include "Objects.h"
#include "Camera.h"
#include "Mario.h"
#include "Sound.h"
#include "blockSize.h"

#define WINDOW_WIDTH 30
#define GAME_NAME "Super Mario"

class Mario;
class Objects;
class CollisionHandler;
class Sound;

class Game {
public:
    Game(std::string mapAddress);
    void run();
    void setMario(Mario* _mario);
    void resetOffset();
    int getWinHeight();
    int getWinOffset();
    void lose();
    void win();

private:
    void drawScreen(int step);
    void processEvents();
    void updateObjects();

    Mario* mario;
    Objects* objects;
    CollisionHandler* collisionHandler;
    Sound* sound;
    Camera* camera;
    int gameStep;
    bool gameRunning;
};

#endif
