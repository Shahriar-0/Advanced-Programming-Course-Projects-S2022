#ifndef __ENEMY_BULLET_HPP__
#define __ENEMY_BULLET_HPP__
#include "rsdl.hpp"
constexpr int SPEED_DOWN = -10;

class SpaceShip;

class EnemyBullet {
public:
    EnemyBullet(Point, SpaceShip*);
    void move_down();
    void update();
    void check_for_hitting_spaceship();
    bool is_dead();
private:
    SpaceShip* spaceShip;
    Point center;
    int vy;
    bool exists;
};

#endif 