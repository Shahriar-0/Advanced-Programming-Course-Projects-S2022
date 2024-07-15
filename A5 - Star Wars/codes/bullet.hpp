#ifndef __BULLET_HPP__
#define __BULLET_HPP__
#include "rsdl.hpp"

constexpr int UP_SPEED          = -60;
constexpr int DOWN_SPEED        = 60;
constexpr int BULLET_LENGTH     = 40;
constexpr int BULLET_WIDTH      = 8;
constexpr int BULLET_RANGE      = 8;
constexpr int BACKGROUND_WIDTH  = 2500;
constexpr int BACKGROUND_HEIGHT = 1650;

enum Type {ENEMY, MY_SPACESHIP};

class Bullet {
public:
    Bullet(Point, Type);
    void move();
    void draw(Window*);
    void update(Window*);
    void check_for_existence(Window*);
    bool does_exist();
    void extinct();
    Point get_center() const;
    Type get_type() const;
private:
    Point center;
    RGB color;
    Type type;
    int vy;
    bool exists;
};

#endif