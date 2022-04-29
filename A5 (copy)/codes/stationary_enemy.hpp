#ifndef __STATIONARY_ENEMY_HPP__
#define __STATIONARY_ENEMY_HPP__
#include "my_space_ship.hpp"
#include "bullet.hpp"

#define STATIONARY_ENEMY_PIC "./assets/pictures/spaceships/stationary_enemy.png"

class StationaryEnemy : public SpaceShip {
public:
    StationaryEnemy(Point, Window*);
    bool is_shot_by(const Bullet&) const;
    bool is_hit_by(const MySpaceShip&) const;
    virtual void update();
    virtual void draw();
};
#endif