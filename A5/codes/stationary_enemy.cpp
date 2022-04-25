#include "stationary_enemy.hpp"

StationaryEnemy::StationaryEnemy(Point _topLeft) : topLeft(_topLeft) {}
StationaryEnemy::StationaryEnemy() : topLeft(Point(0, 0)) {}

void StationaryEnemy::draw(Window* win) {
    win->draw_img(STATIONARY_ENEMY_PIC, Rectangle(topLeft, blockWidth, blockHeight));
}

void StationaryEnemy::update(Window* win) {
    update_bullets(win);
    if (!is_dead()) 
        draw(win);
}

void StationaryEnemy::update_bullets(Window* win) {
    for (auto& bullet : bullets) 
        bullet.update(win);
}

// bool StationaryEnemy::is_hitting(MyBullet bullet) {
//     Point center = topLeft + Point(blockWidth / 2, blockHeight / 2);
//     Point bulletCenter = bullet.get_center();
//     return sqrt(pow(abs(center.x - bulletCenter.x), 2) + pow(abs(center.y - bulletCenter.y), 2)) <= 
//         LEAST_DISTANCE_FOR_BULLETS;
// }
//todo: fix this

Point StationaryEnemy::get_center() { return topLeft + Point(blockWidth / 2, blockHeight / 2); }
bool StationaryEnemy::is_dead() { return exists == false; }
void StationaryEnemy::die() { exists = false; }