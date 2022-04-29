#include "stationary_enemy.hpp"

StationaryEnemy::StationaryEnemy(Point _topLeft, Window* _win)
    : SpaceShip(_topLeft, _win) {
    vx = vy = 0;
    stamina = 1; //cause the enemies have only one life yet
}

void StationaryEnemy::update() {
    if (is_dead())
        return;
    draw();
}

void StationaryEnemy::draw() { win->draw_img(STATIONARY_ENEMY_PIC, Rectangle(topLeft, blockWidth, blockHeight)); }