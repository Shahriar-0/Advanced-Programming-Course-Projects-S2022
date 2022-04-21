#ifndef BRICK_BLOCK_H
#define BRICK_BLOCK_H

#include "rsdl.hpp"
#include "blockSize.h"

#define HIT_MOVE 3

#define BRICK_BLOCK_PNG "assets/sprites/objects/bricks_blocks/brick.png"
#define BRICK_BROKEN_PNG "assets/sprites/objects/bricks_blocks/brick-debris.png"

class BrickBlock {
public:
    BrickBlock(Point _position);
    void draw(Window* win, int winOffset);
    Rectangle* getPositionPointer();
    void hit(bool isMarioBig);
private:
    Rectangle position;
    int showHitFrames;
    bool broken;
};

#endif