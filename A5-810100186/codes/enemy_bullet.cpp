#include "enemy_bullet.hpp"

EnemyBullet::EnemyBullet(Point _center, int _blockWidth, int _blockHeight) : center(_center) {
    exists = true;
    vy = DOWN_SPEED;
    length = ENEMY_BULLET_LENGTH;
    blockWidth = _blockWidth;
    blockHeight = _blockHeight;
}

void EnemyBullet::check_for_existence(Window* win) {
    if (center.x < 0 || center.x >= win->get_width() || center.y < 0 || center.y >= win->get_height())
        extinct();
}

void EnemyBullet::update(Window* win) {
    check_for_existence(win);
    if (!does_exist())
        return;
    move();
    draw(win);
}

void EnemyBullet::move() { center.y += vy; }

bool EnemyBullet::is_colliding(Point target) {
    return sqrt(pow(abs(target.x - center.x), 2) + pow(abs(target.y - center.y), 2)) <= ENEMY_BULLET_RANGE
    || sqrt(pow(abs(target.x - center.x), 2) + pow(abs(target.y - center.y + blockHeight / 2), 2)) <= ENEMY_BULLET_RANGE
    || sqrt(pow(abs(target.x - center.x), 2) + pow(abs(target.y - center.y - blockHeight / 2), 2)) <= ENEMY_BULLET_RANGE;
}

void EnemyBullet::draw(Window* win) { win->draw_line(Point(center.x, center.y - blockHeight / 2), Point(center.x, center.y + blockHeight / 2), RED); }
void EnemyBullet::extinct() { exists = false; }
bool EnemyBullet::does_exist() { return exists; }