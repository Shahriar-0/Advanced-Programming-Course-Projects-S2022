#include "moving_enemy.hpp"

MovingEnemy::MovingEnemy(Point _topLeft, int _blockWidth, int _blockHeight) : topLeft(_topLeft) {
    blockWidth = _blockWidth;
    blockHeight = _blockHeight;
    frameCounter = 0;
}

void MovingEnemy::draw(Window* win) {
    win->draw_img(MOVING_ENEMY_PIC, Rectangle(topLeft, blockWidth, blockHeight));
}

void MovingEnemy::update(Window* win) {
    update_bullets();
    if (!is_dead()) {
        move();
        draw(win);
    }
}

void MovingEnemy::move() {
    vx = (rand() % 2)? MOVING_LEFT_SPEED : MOVING_RIGHT_SPEED;
    topLeft.x += vx;
}

bool MovingEnemy::is_hitting(MyBullet bullet) {
    Point center = topLeft + Point(blockWidth / 2, blockHeight / 2);
    Point bulletCenter = bullet.get_center();
    return sqrt(pow(abs(center.x - bulletCenter.x), 2) + pow(abs(center.y - bulletCenter.y), 2)) <= 
        LEAST_DISTANCE_FOR_BULLETS;
}

bool MovingEnemy::is_dead() { return exists == false; }
void MovingEnemy::die() { exists = false; }