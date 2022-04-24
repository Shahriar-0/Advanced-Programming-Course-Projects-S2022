#include "my_bullet.hpp"

MyBullet::MyBullet(Point _center, MovingEnemies* _lisrOfMovingEnemies,
 StationaryEnemies* _listOfStationaryEnemies, Hostage* _hostage) 
    : center(_center) { 
    listOfMovingEnemies = _lisrOfMovingEnemies;
    listOfStationaryEnemies = _listOfStationaryEnemies;
    hostage = _hostage;
    vy = SPEED_UP;
    exists = true;
}

void MyBullet::move() { center.y += vy; }

