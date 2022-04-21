#ifndef NORMAL_BLOCK_H
#define NORMAL_BLOCK_H

#include "rsdl.hpp"
#include "blockSize.h"
#include "string"
#include <map>

#define GROUND_BLOCK '#'
#define NORMAL_BLOCK '@'

#define GROUND_BLOCK_PNG "assets/sprites/objects/bricks_blocks/clay.png"
#define NORMAL_BLOCK_PNG "assets/sprites/objects/bricks_blocks/block.png"

const std::map<char, std::string> BLOCKS_PNG = {{GROUND_BLOCK, GROUND_BLOCK_PNG}
    , {NORMAL_BLOCK, NORMAL_BLOCK_PNG}};

class NormalBlock {
public:
    NormalBlock(Point pos, char _type);
    void draw(Window* win, int winOffset);
    Rectangle* getPositionPointer();
private:
    Rectangle position;
    char type;
};

#endif
