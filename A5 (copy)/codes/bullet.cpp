#include "bullet.hpp"

Bullet::Bullet(Point _center, int _blockWidth, int _blockHeight, Type type) : 
    center(_center), color(WHITE), blockWidth(_blockWidth), blockHeight(_blockHeight) { 
    vy = (type == ENEMY)? DOWN_SPEED : UP_SPEED;
    color = (type == ENEMY)? RED : GREEN;
    exists = true;
}

void Bullet::update(Window* win) {
    if (!does_exist())
        return;
    check_for_existence(win);
    move();
    draw(win);
}

void Bullet::check_for_existence(Window* win) {
    if (center.x < 0 || center.x >= win->get_width() || center.y < 0 || center.y >= win->get_height())
        extinct();
}

Point Bullet::get_center() const { return center; }
void Bullet::move() { center.y += vy; }
void Bullet::draw(Window* win) { win->fill_rect(Rectangle(Point(center.x - BULLET_WIDTH / 2, center.y - BULLET_LENGTH / 2), Point(center.x + BULLET_WIDTH / 2, center.y + BULLET_LENGTH / 2)), color); }
bool Bullet::does_exist() { return exists == true; }
void Bullet::extinct() { exists = false; }