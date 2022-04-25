#ifndef __STATIONARY_ENEMIES_HPP__
#define __STATIONARY_ENEMIES_HPP__
#include "stationary_enemy.hpp"
#include "audio.hpp"
#include <vector>

class StationaryEnemies {
public:
    int count_alive();
    bool any_member_is_hitting(MyBullet*);
    void update();
private:
    Window* win;
    AudioPlayer* musicPlayerptr;
    std::vector<StationaryEnemy> list;
};

#endif 