#include "Flag.h"

Flag::Flag(Point headPos, int _height)
    :position(headPos, BLOCK_SIZE, _height * BLOCK_SIZE),
     height(_height) {}

void Flag::draw(Window* win, int winOffset) {
    drawHead(win, winOffset);
    if (height > 1)
        drawBody(win, winOffset);
}

void Flag::drawHead(Window* win, int winOffset) {
    win->draw_img(
        FLAG_HEAD_PNG,
        Rectangle(position.x - winOffset, position.y,
        BLOCK_SIZE, BLOCK_SIZE)
    );
}

void Flag::drawBody(Window* win, int winOffset) {
    for (int i = 1; i < height; i++) {
        win->draw_img(
            FLAG_BODY_PNG,
            Rectangle(position.x - winOffset, position.y + i * BLOCK_SIZE,
            BLOCK_SIZE, BLOCK_SIZE)
        );
    }
}

Rectangle* Flag::getPositionPointer() {
    return &position;
}
