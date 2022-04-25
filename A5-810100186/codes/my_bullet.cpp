#include "my_bullet.hpp"

MyBullet::MyBullet(Point _center, int _blockWidth, int _blockHeight) : center(_center) { 
    vy = UP_SPEED;
    exists = true;
    blockWidth = _blockWidth;
    blockHeight = _blockHeight;
}

void MyBullet::update(Window* win) {
    check_for_existence(win);
    if (!does_exist())
        return;
    move();
    draw(win);
}

void MyBullet::check_for_existence(Window* win) {
    if (center.x < 0 || center.x >= win->get_width() || center.y < 0 || center.y >= win->get_height())
        extinct();
}

void MyBullet::move() { center.y += vy; }

bool MyBullet::is_colliding(Point target) {
    return sqrt(pow(abs(target.x - center.x), 2) + pow(abs(target.y - center.y), 2)) <= MY_BULLET_RANGE
    || sqrt(pow(abs(target.x - center.x), 2) + pow(abs(target.y - center.y + blockHeight / 2), 2)) <= MY_BULLET_RANGE
    || sqrt(pow(abs(target.x - center.x), 2) + pow(abs(target.y - center.y - blockHeight / 2), 2)) <= MY_BULLET_RANGE;
}

void MyBullet::draw(Window* win) { win->draw_line(Point(center.x, center.y - blockHeight / 2), Point(center.x, center.y + blockHeight / 2), GREEN); }
bool MyBullet::does_exist() { return exists == false; }
void MyBullet::extinct() { exists = false; }