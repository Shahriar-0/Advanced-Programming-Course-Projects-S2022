#include "my_bullet.hpp"

MyBullet::MyBullet(Point _center, MovingEnemies* _lisrOfMovingEnemies,
 StationaryEnemies* _listOfStationaryEnemies, Hostage* _hostage) 
    : center(_center) { 
    listOfMovingEnemies = _lisrOfMovingEnemies;
    listOfStationaryEnemies = _listOfStationaryEnemies;
    hostage = _hostage;
    vy = UP_SPEED;
    exists = true;
}

void MyBullet::move() { center.y += vy; }

bool MyBullet::is_colliding(Point target) {
    return sqrt(pow(abs(target.x - center.x), 2) + pow(abs(target.y - center.y), 2)) <= LEAST_DISTANCE_FOR_MY_BULLETS;
}

void MyBullet::check_for_hitting_hostage() {
    if (is_colliding(hostage->get_center())) {
        hostage->die();
        extinct();
    }
}

bool MyBullet::is_dead() { return exists == false; }
void MyBullet::extinct() { exists = false; }