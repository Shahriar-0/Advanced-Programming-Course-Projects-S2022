#ifndef __STATIONARY_ENEMY_HPP__
#define __STATIONARY_ENEMY_HPP__
#include "bullet.hpp"
#include <vector>
#include <cmath>

#define STATIONARY_ENEMY_PIC "./assets/pictures/spaceships/stationary_enemy.png"

class StationaryEnemy {
public:
    StationaryEnemy(Point, int, int);
    void draw(Window*);
    void update(Window*); 
    bool is_dead();
    void die();
    // bool is_hitting(MyBullet*);
    void shoot();
    Point get_center();
    void play_explosion_sound();
    void update_bullets(); //remember to update bullets no matter what
    int blockWidth, blockHeight;
private:
    Point topLeft;
    std::vector<Bullet> enemyBullets;
    bool exists;
};

#endif