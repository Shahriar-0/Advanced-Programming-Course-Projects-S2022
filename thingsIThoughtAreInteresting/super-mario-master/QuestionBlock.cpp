#include "QuestionBlock.h"

QuestionBlock::QuestionBlock(Point pos, char _type):
    position(pos, BLOCK_SIZE, BLOCK_SIZE), type(_type) {
        isHit = false;
        showHitFrames = frameDelay = showCoinFrames = 0;
    }

void QuestionBlock::draw(Window* win, int winOffset, int step) {
    if (step % 4 == 0)
        frameDelay++;
    if (!isHit) {
        win->draw_img(
            Q_BLOCK_PNG[frameDelay % 3],
            Rectangle(position.x - winOffset, position.y , BLOCK_SIZE, BLOCK_SIZE)
        );
    }
    else {
        if (showHitFrames) {
            win->draw_img(
           Q_BLOCK_EMPTY,
            Rectangle(position.x - winOffset, position.y - showHitFrames * HIT_MOVE , BLOCK_SIZE, BLOCK_SIZE)
            );
            showHitFrames--;
        }
        else {
            win->draw_img(
                Q_BLOCK_EMPTY,
                Rectangle(position.x - winOffset, position.y , BLOCK_SIZE, BLOCK_SIZE)
            );
        }
    }
    if (showCoinFrames) {
        win->draw_img(
            COIN_PNG,
            Rectangle(position.x - winOffset, position.y - BLOCK_SIZE * 2 + showCoinFrames * COIN_MOVE , BLOCK_SIZE, BLOCK_SIZE)
        );
        showCoinFrames--;
    }
}

Rectangle* QuestionBlock::getPositionPointer() {
    return &position;
}

char QuestionBlock::hit() {
    if (!isHit) {
        showHitFrames = 5;
        isHit = true;
        switch(type) {
            case COIN_BLOCK:
                showCoinFrames = 20;
                return COIN_BLOCK;
        }
    }
}