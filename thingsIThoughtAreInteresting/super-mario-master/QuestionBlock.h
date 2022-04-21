#ifndef QBLOCK_H
#define QBLOCK_H

#include "rsdl.hpp"
#include "blockSize.h"
#include <array>

#define Q_BLOCK_1 "assets/sprites/objects/bricks_blocks/question-1.png"
#define Q_BLOCK_2 "assets/sprites/objects/bricks_blocks/question-2.png"
#define Q_BLOCK_3 "assets/sprites/objects/bricks_blocks/question-3.png"
#define Q_BLOCK_EMPTY "assets/sprites/objects/bricks_blocks/question-empty.png"
#define COIN_PNG "assets/sprites/objects/coin.png"
#define HIT_MOVE 3
#define COIN_MOVE 3

const std::array<std::string, 3> Q_BLOCK_PNG = {
    Q_BLOCK_1,
    Q_BLOCK_2,
    Q_BLOCK_3
    };

#define COIN_BLOCK '?'
#define RED_MUSHROOM_BLOCK 'm'
#define HEALTH_BLOCK 'h'
#define EMPTY '.'

class QuestionBlock {
public:
    QuestionBlock(Point pos, char _type);
    void draw(Window* win, int winOffset, int step);
    Rectangle* getPositionPointer();
    char hit();

private:
    Rectangle position;
    char type;
    bool isHit;
    int showHitFrames;
    int showCoinFrames;
    int frameDelay;
};

#endif 