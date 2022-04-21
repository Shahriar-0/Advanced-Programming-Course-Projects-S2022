#include "BrickBlock.h"

BrickBlock::BrickBlock (Point _position): 
        position(_position, BLOCK_SIZE, BLOCK_SIZE) {
    showHitFrames = 0;
    broken = false;

    }

void BrickBlock::draw(Window* win, int winOffset) {
    if (broken && showHitFrames) {
        win->draw_img(
            BRICK_BROKEN_PNG,
            Rectangle(position.x - winOffset, position.y - showHitFrames * HIT_MOVE , BLOCK_SIZE, BLOCK_SIZE)
        );
        showHitFrames--;
        position.x = position.y = -100;
    }
    if (showHitFrames) {
        win->draw_img(
            BRICK_BLOCK_PNG,
            Rectangle(position.x - winOffset, position.y - showHitFrames * HIT_MOVE , BLOCK_SIZE, BLOCK_SIZE)
        );
        showHitFrames--;
    } 
    else {
        win->draw_img(
            BRICK_BLOCK_PNG,
            Rectangle(position.x - winOffset, position.y , BLOCK_SIZE, BLOCK_SIZE)
        );
    }
}

Rectangle* BrickBlock::getPositionPointer() {
    return &position;
}

void BrickBlock::hit(bool isMarioBig) {
    if (isMarioBig) {
        broken = true;
        showHitFrames = 1;
    } else {
        showHitFrames = 5;
    }
}