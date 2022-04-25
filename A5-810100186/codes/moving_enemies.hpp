#ifndef __MOVING_ENEMIES_HPP__
#define __MOVING_ENEMIES_HPP__

#include "moving_enemy.hpp"
#include <vector>

class MovingEnemies {
public:
    int count_alive();
    bool any_member_is_hitting(MyBullet*);
private:
    std::vector<MovingEnemy> list;
};


#endif 