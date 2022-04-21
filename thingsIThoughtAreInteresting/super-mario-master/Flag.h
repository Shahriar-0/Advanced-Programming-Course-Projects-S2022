#ifndef FLAG_H
#define FLAG_H

#include "rsdl.hpp"
#include "blockSize.h"

#define FLAG_HEAD_PNG "assets/sprites/objects/flag/head.png"
#define FLAG_BODY_PNG "assets/sprites/objects/flag/body.png"

class Flag {
public:
    Flag(Point headPos, int _height);
    void draw(Window* win, int winOffset);
    Rectangle* getPositionPointer();

private:
    void drawHead(Window* win, int winOffset);
    void drawBody(Window* win, int winOffset);

    Rectangle position;
    int height;
};

#endif
