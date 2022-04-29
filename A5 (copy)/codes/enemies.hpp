#ifndef __ENEMIES_HPP__
#define __ENEMIES_HPP__
#include <vector>
#include "moving_enemy.hpp"
#include "audio.hpp"
#include "bullet.hpp"

class Enemies {
public: 
    Enemies() = default;
    int count_alive();
    void add_member(StationaryEnemy*);
    void update(MySpaceShip&, std::vector<Bullet>&);
    void initialise();
private:
    std::vector<StationaryEnemy*> list;
};

#endif