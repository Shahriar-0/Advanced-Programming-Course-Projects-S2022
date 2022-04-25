#include "moving_enemy.hpp"

MovingEnemy::MovingEnemy(Point _topLeft) : topLeft(_topLeft) {}

void MovingEnemy::draw(Window* win) {
    win->draw_img(MOVING_ENEMY_PIC, Rectangle(topLeft, blockWidth, blockHeight));
}

void MovingEnemy::update(Window* win) {
    update_bullets(win);
    if (is_dead())
        return;
    move();
    draw(win);
}

void MovingEnemy::move() {
    vx = (rand() % 2)? MOVING_LEFT_SPEED : MOVING_RIGHT_SPEED;
    topLeft.x += vx;
}
