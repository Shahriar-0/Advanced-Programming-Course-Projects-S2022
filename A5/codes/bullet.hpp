#ifndef __BULLET_HPP__
#define __BULLET_HPP__
#include "rsdl.hpp"
#include <cmath>
constexpr int UP_SPEED = 10;
constexpr int DOWN_SPEED = -10;
constexpr int BULLET_LENGTH = 15;
constexpr double BULLET_RANGE = 8;

enum Type {ENEMY, MY_SPACESHIP};

class Bullet {
public:
    Bullet(Point, int, int, Type);
    void move();
    void draw(Window*);
    void update(Window*);
    void check_for_existence(Window*);
    bool is_colliding(Point);
    bool does_exist();
    void extinct();
private:
    Point center;
    RGB color;
    int vy;
    bool exists;
    int blockWidth, blockHeight;
};

#endif