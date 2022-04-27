#include "moving_enemy.hpp"

MovingEnemy::MovingEnemy(Point _topLeft, int _blockWidth, int _blockHeight) : topLeft(_topLeft) {
    blockWidth = _blockWidth;
    blockHeight = _blockHeight;
}


void MovingEnemy::update(Window* win) {
    update_bullets(win);
    if (is_dead())
        return;
    move();
    draw(win);
    if (frameCounter == 0) {
        shoot();
        frameCounter = rand() % FRAME_LIMIT;
    }   
}

void MovingEnemy::move() {
    vx = (rand() % 2)? MOVING_LEFT_SPEED : MOVING_RIGHT_SPEED;
    topLeft.x += vx;
}

void MovingEnemy::draw(Window* win) { win->draw_img(MOVING_ENEMY_PIC, Rectangle(topLeft, blockWidth, blockHeight)); }