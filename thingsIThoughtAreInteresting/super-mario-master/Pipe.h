#ifndef PIPE_H
#define PIPE_H

#include "rsdl.hpp"
#include "blockSize.h"

#define PIPE_HEAD_L "assets/sprites/objects/pipe/head-left.png"
#define PIPE_HEAD_R "assets/sprites/objects/pipe/head-right.png"
#define PIPE_BODY_L "assets/sprites/objects/pipe/left.png"
#define PIPE_BODY_R "assets/sprites/objects/pipe/right.png"

class Pipe {
public:
    Pipe(Point headLeftPos, int _height);
    void draw(Window* win, int winOffset);
    Rectangle* getPositionPointer();

private:
    void drawHead(Window* win, int winOffset);
    void drawBody(Window* win, int winOffset);
    
    Rectangle position;
    int height;
};

#endif
