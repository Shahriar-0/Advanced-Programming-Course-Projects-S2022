#ifndef __ENEMY_BULLET_HPP__
#define __ENEMY_BULLET_HPP__
#include "rsdl.hpp"
constexpr int DOWN_SPEED = -10;
constexpr int ENEMY_BULLET_LENGTH = 10;
constexpr double ENEMY_BULLET_RANGE = 8;
class SpaceShip;

class EnemyBullet {
public:
    EnemyBullet(Point, int, int);
    void move();
    void update(Window*);
    void check_for_existence(Window*);
    bool does_exist();
    void extinct();
    bool is_colliding(Point);
    void draw(Window*);
private:
    Point center;
    int vy;
    int length;
    bool exists;
    int blockWidth, blockHeight;
};

#endif 