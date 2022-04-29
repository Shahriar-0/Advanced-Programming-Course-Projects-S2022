#include "moving_enemy.hpp"

MovingEnemy::MovingEnemy(Point _topLeft, Window* _win)
    : StationaryEnemy(_topLeft, _win) {
    vx = HORIZONTAL_SPEED;
}

void MovingEnemy::update() {
    if (is_dead())
        return;
    move();
    put_in_frame();
    draw();
}

void MovingEnemy::put_in_frame() {
    if (topLeft.x <= 0) {
        topLeft.x = 0;
        vx *= -1;
    }
    else if (topLeft.x + blockWidth >= win->get_width()) {
        topLeft.x = win->get_width() - blockWidth;
        vx *= -1;
    }
}

void MovingEnemy::draw() { win->draw_img(MOVING_ENEMY_PIC, Rectangle(topLeft, blockWidth, blockHeight)); }