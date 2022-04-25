#include "enemy_bullet.hpp"

EnemyBullet::EnemyBullet(Point _center) : center(_center) {
    exists = true;
    vy = DOWN_SPEED;
    length = MY_BULLET_LENGTH;
}

void EnemyBullet::check_for_existence(Window* win) {
    if (center.x < 0 || center.x >= win->get_width() || center.y < 0 || center.y >= win->get_height())
        extinct();
}

void EnemyBullet::update(Window* win) {
    check_for_existence(win);
    if (!does_exist())
        return;
    
}

void EnemyBullet::extinct() { exists = false; }
bool EnemyBullet::does_exist() { return exists; }