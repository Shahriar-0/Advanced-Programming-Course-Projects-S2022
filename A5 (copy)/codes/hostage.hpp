#ifndef __HOSTAGE_HPP__
#define __HOSTAGE_HPP__
#include "stationary_enemy.hpp"
#define HOSTAGE_PIC "./assets/pictures/spaceships/hostage.png"

class Hostage : public SpaceShip {
public:
    Hostage(Point, Window*, int, int, AudioPlayer*);
    bool is_shot_by(const Bullet&) const;
    virtual void update();
    virtual void draw();
};

#endif