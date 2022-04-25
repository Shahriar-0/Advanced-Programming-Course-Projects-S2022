#ifndef __MY_BULLET_HPP__
#define __MY_BULLET_HPP__
#include "rsdl.hpp"
#include "moving_enemies.hpp"
#include "hostage.hpp"
#include "stationary_enemies.hpp"
constexpr int UP_SPEED = 10;
constexpr int MY_BULLET_LENGTH = 10;
constexpr double LEAST_DISTANCE_FOR_MY_BULLETS = 8;

class MyBullet {
public:
    MyBullet(Point, MovingEnemies*, StationaryEnemies*, Hostage*);
    void move();
    void draw(Window*);
    void update(Window*);
    void check_for_existence(Window*);
    void check_for_hitting_hostage();
    void check_for_hitting_moving_enenmy();
    void check_for_hitting_stationary_enemy();
    bool is_colliding(Point);
    bool is_dead();
    void extinct();
private:
    MovingEnemies* listOfMovingEnemies;
    StationaryEnemies* listOfStationaryEnemies;
    Hostage* hostage;
    Point center;
    int vy;
    bool exists;
};

#endif