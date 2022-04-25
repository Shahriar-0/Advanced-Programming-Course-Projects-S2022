#ifndef __MOVING_ENEMIES_HPP__
#define __MOVING_ENEMIES_HPP__
#include "audio.hpp"
#include "moving_enemy.hpp"
#include <vector>

class MovingEnemies{
public:
    MovingEnemies(Window*, AudioPlayer*);
    int count_alive();
    bool any_member_is_hitting(MyBullet*);
    void update();
    Window* win;
    AudioPlayer* musicPlayerptr;
private:
    std::vector<MovingEnemy> list;
};

#endif 