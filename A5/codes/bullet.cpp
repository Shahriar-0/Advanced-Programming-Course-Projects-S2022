#include "bullet.hpp"

Bullet::Bullet(Point _center, int _blockWidth, int _blockHeight, Type type) : 
    center(_center), color(WHITE), blockWidth(_blockWidth), blockHeight(_blockHeight) { 
    vy = (type == ENEMY)? DOWN_SPEED : UP_SPEED;
    color = (type == ENEMY)? RED : GREEN;
    exists = true;
}

void Bullet::update(Window* win) {
    check_for_existence(win);
    if (!does_exist())
        return;
    move();
    draw(win);
}

void Bullet::check_for_existence(Window* win) {
    if (center.x < 0 || center.x >= win->get_width() || center.y < 0 || center.y >= win->get_height())
        extinct();
}

void Bullet::move() { center.y += vy; }

bool Bullet::is_colliding(Point target) {
    return sqrt(pow(abs(target.x - center.x), 2) + pow(abs(target.y - center.y), 2)) <= BULLET_RANGE
    || sqrt(pow(abs(target.x - center.x), 2) + pow(abs(target.y - center.y + blockHeight / 2), 2)) <= BULLET_RANGE
    || sqrt(pow(abs(target.x - center.x), 2) + pow(abs(target.y - center.y - blockHeight / 2), 2)) <= BULLET_RANGE;
}

void Bullet::draw(Window* win) { win->draw_line(Point(center.x, center.y - blockHeight / 2), Point(center.x, center.y + blockHeight / 2), color); }
bool Bullet::does_exist() { return exists == false; }
void Bullet::extinct() { exists = false; }