#ifndef __MOVING_ENEMIES_HPP__
#define __MOVING_ENEMIES_HPP__
#include "audio.hpp"
#include "moving_enemy.hpp"
#include "rsdl.hpp"
#include <vector>

class MovingEnemies{
public:
    MovingEnemies(Window*, AudioPlayer*);
    int count_alive();
    bool any_member_is_hitting(); //probably spaceship*
    void update();
private:
    Window* win;
    AudioPlayer* musicPlayerptr;
    std::vector<MovingEnemy> list;
};

#endif 