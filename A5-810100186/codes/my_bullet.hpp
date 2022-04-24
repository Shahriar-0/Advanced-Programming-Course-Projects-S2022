#ifndef __MY_BULLET_HPP__
#define __MY_BULLET_HPP__
#include "rsdl.hpp"

constexpr int SPEED_UP = 10;
constexpr double LEAST_DISTANCE_FOR_BULLETS = 8;


class MovingEnemies;
class StationaryEnemies;
class Hostage;

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
    bool is_dead();
    Point get_center();
private:
    MovingEnemies* listOfMovingEnemies;
    StationaryEnemies* listOfStationaryEnemies;
    Hostage* hostage;
    Point center;
    int vy;
    bool exists;
};

#endif