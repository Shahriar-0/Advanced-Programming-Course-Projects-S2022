#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include "rsdl.hpp"
#include "Game.h"
#include "Objects.h"
#include "Mario.h"
#include "QuestionBlock.h"
#include "BrickBlock.h"
#include "LittleGoomba.h"
#include "KoopaTroopa.h"

#define MARIO 'M'
#define PIPE '|'
#define FLAG 'f'
#define EMPTY '.'
#define SIMPLE_BRICK 'b'
#define COIN_BLOCK '?'
#define RED_MUSHROOM_BLOCK 'm'
#define HEALTH_BLOCK 'h'
#define GROUND_BLOCK '#'
#define NORMAL_BLOCK '@'
#define KOOPA_TROOPA 'k'
#define LITTLE_GOOMBA 'l'

class Game;
class Objects;

class Map {
public:
    Map(Game* _game, Objects* _objects);
    void initGameSetup();
    int getMapHeight();
    void readMap(std::string mapAddress);

private:
    void processMapRow(std::vector<char>& mapRow, int row);
    void processChar(char c, Point pos);
    int findPipeHeight(int headRow, int headCol);
    void clearPipe(int headRow, int headCol);
    int findFlagHeight(int headRow, int headCol);
    void clearFlag (int headRow, int headCol);

    std::vector<std::vector<char>> map;
    Objects* objects;
    Game* game;
};

#endif
