#ifndef __ENEMY_BULLET_HPP__
#define __ENEMY_BULLET_HPP__
#include "rsdl.hpp"
constexpr int SPEED_DOWN = -10;
constexpr int BULLET_LENGTH = 10;
class SpaceShip;

class EnemyBullet {
public:
    EnemyBullet(Point, SpaceShip*);
    void move();
    void update(Window*);
    void check_for_hitting_spaceship();
    void check_for_existence(Window*);
    bool does_exist();
    void extinct();
    void draw(Window*);
private:
    SpaceShip* spaceShip;
    Point center;
    int vy;
    int length;
    bool exists;
};

#endif 