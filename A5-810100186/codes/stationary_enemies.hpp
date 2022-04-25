#ifndef __STATIONARY_ENEMIES_HPP__
#define __STATIONARY_ENEMIES_HPP__
#include "stationary_enemy.hpp"
#include <vector>

class StationaryEnemies {
public:
    int count_alive();
    bool any_member_is_hitting(MyBullet*);
private:
    std::vector<StationaryEnemy> list;
};

#endif 