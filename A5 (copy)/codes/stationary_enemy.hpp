#ifndef __STATIONARY_ENEMY_HPP__
#define __STATIONARY_ENEMY_HPP__
#include "my_space_ship.hpp"
#include "bullet.hpp"

#define STATIONARY_ENEMY_PIC "./assets/pictures/spaceships/stationary_enemy.png"
constexpr int MINIMUM_DELTA_X_SHIPS = 90;
constexpr int MINIMUM_DELTA_Y_SHIPS = 90;

class StationaryEnemy : public SpaceShip {
public:
    StationaryEnemy(Point, Window*, int, int, AudioPlayer*);
    bool is_shot_by(const Bullet&) const;
    bool is_hit_by(const MySpaceShip&) const;
    virtual void update();
    virtual void draw();
};
#endif