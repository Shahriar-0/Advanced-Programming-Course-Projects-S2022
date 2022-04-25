#ifndef __MY_BULLET_HPP__
#define __MY_BULLET_HPP__
#include "rsdl.hpp"
constexpr int UP_SPEED = 10;
constexpr int MY_BULLET_LENGTH = 10;
constexpr double MY_BULLET_RANGE = 8;

class MyBullet {
public:
    MyBullet(Point, int, int);
    void move();
    void draw(Window*);
    void update(Window*);
    void check_for_existence(Window*);
    bool is_colliding(Point);
    bool does_exist();
    void extinct();
private:
    Point center;
    int vy;
    bool exists;
    int blockWidth, blockHeight;
};

#endif