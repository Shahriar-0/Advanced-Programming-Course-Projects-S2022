#ifndef __HOSTAGE_HPP__
#define __HOSTAGE_HPP__
#include "rsdl.hpp"

#define HOSTAGE_PIC "./assets/pictures/spaceships/hostage.png.png"

class Hostage {
public:
    Hostage(Point, int, int);
    void draw(Window*);
private:
    Point topLeft;
    bool exists;
    int blockWidth, blockHeight;
};

#endif