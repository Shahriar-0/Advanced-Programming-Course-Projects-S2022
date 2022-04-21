#include "Pipe.h"
#include <iostream>

Pipe::Pipe(Point headLeftPos, int _height)
    :position(headLeftPos, 2 * BLOCK_SIZE, _height * BLOCK_SIZE),
     height(_height) {
}

Rectangle* Pipe::getPositionPointer() {
    return &position;
}

void Pipe::draw(Window* win, int winOffset) {
    drawHead(win, winOffset);
    if (height > 1)
        drawBody(win, winOffset);
}

void Pipe::drawHead(Window* win, int winOffset) {
    win->draw_img(
        PIPE_HEAD_L,
        Rectangle(position.x - winOffset, position.y,
            BLOCK_SIZE, BLOCK_SIZE)
    );
    win->draw_img(
        PIPE_HEAD_R,
        Rectangle(position.x - winOffset + BLOCK_SIZE, position.y,
            BLOCK_SIZE, BLOCK_SIZE)
    );
}

void Pipe::drawBody(Window* win,int winOffset) {
    for (int i = 1; i < height; i++) {
        win->draw_img(
            PIPE_BODY_L,
            Rectangle(position.x - winOffset, position.y + i * BLOCK_SIZE,
                BLOCK_SIZE, BLOCK_SIZE)
        );
        win->draw_img(
            PIPE_BODY_R,
            Rectangle(position.x - winOffset + BLOCK_SIZE, position.y + i * BLOCK_SIZE,
                BLOCK_SIZE, BLOCK_SIZE)
        );
    }
}
