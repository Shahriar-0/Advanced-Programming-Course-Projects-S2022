#ifndef __STATIONARY_ENEMY_HPP__
#define __STATIONARY_ENEMY_HPP__
#include "my_bullet.hpp"
#include "enemy_bullet.hpp"
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
    bool is_hitting(MyBullet);
    void shoot();
private:
    int frameCounter;
    void update_bullets(); //remember to update bullets no matter what
    Point topLeft;
    std::vector<EnemyBullet> enemyBullets;
    bool exists;
    int blockWidth, blockHeight;
};

#endif