#include "enemy_bullet.hpp"

EnemyBullet::EnemyBullet(Point _center, SpaceShip* _spaceShip) : center(_center) {
    spaceShip = _spaceShip;
    exists = true;
    vy = SPEED_DOWN;
}