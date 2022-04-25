#ifndef __MOVING_ENEMY_HPP__
#define __MOVING_ENEMY_HPP__
#include "enemy_bullet.hpp"
#include <vector>

#define MOVING_ENEMY_PIC "./assets/pictures/spaceships/moving_enemy.jpeg"
const int MOVING_RIGHT_SPEED = 10;
const int MOVING_LEFT_SPEED = 10;

class MovingEnemy {
public:
    MovingEnemy(Point, int, int);
    void draw(Window*);
    void update(Window*); 
    bool is_dead();
    void die();
    // bool is_hitting(MyBullet*);
    void move();
    void shoot();
    Point get_center();
    void play_explosion_sound();
    void update_bullets(); //remember to update bullets no matter what
private:
    int frameCounter;
    int vx;
    Point topLeft;
    std::vector<EnemyBullet> enemyBullets;
    bool exists;
    int blockWidth, blockHeight;
};

#endif