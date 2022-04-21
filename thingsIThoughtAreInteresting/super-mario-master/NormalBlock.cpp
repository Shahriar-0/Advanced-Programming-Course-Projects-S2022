#include "NormalBlock.h"

NormalBlock::NormalBlock(Point pos, char _type)
    :position(pos, BLOCK_SIZE, BLOCK_SIZE),
     type(_type) {}

void NormalBlock::draw(Window* win, int winOffset) {
    win->draw_img (
        BLOCKS_PNG.at(type),
        Rectangle(position.x - winOffset, position.y , BLOCK_SIZE, BLOCK_SIZE)
    );
}

Rectangle* NormalBlock::getPositionPointer() {
    return &position;
}
