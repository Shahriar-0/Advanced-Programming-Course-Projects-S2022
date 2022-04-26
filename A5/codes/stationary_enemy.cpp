#include "stationary_enemy.hpp"
using namespace std;


StationaryEnemy::StationaryEnemy(Point _topLeft) : topLeft(_topLeft) { frameCounter = rand() % FRAME_LIMIT;}
StationaryEnemy::StationaryEnemy() : topLeft(Point(0, 0)) {}

void StationaryEnemy::draw(Window* win) {
    win->draw_img(STATIONARY_ENEMY_PIC, Rectangle(topLeft, blockWidth, blockHeight));
}

void StationaryEnemy::update(Window* win) {
    update_bullets(win);
    if (is_dead())
        return;
    draw(win);
    if (frameCounter == 0) {
        shoot();
        frameCounter = rand() % FRAME_LIMIT;
    }   
}

void StationaryEnemy::shoot() {
    bullets.push_back(Bullet(get_center(), blockWidth, blockHeight, ENEMY));
}

void StationaryEnemy::update_bullets(Window* win) {
    for (auto& bullet : bullets) 
        bullet.update(win);
}

void StationaryEnemy::check_for_hitting_spaceship(SpaceShip* spaceShipPtr) {
    for (auto& bullet : bullets) {
        if (bullet.is_colliding(spaceShipPtr->get_center())) {
            spaceShipPtr->get_shot();
            bullet.extinct();
        }
    }
}

bool StationaryEnemy::check_for_getting_hit(SpaceShip* spaceShipPtr) {
    vector<Bullet>* spaceShipBulletsPtr;
    for (auto& bullet : *spaceShipBulletsPtr) {
        if (bullet.is_colliding(get_center())) {
            die();
            bullet.extinct();
            return true;
        }
    }
    return false;
}

Point StationaryEnemy::get_center() { return topLeft + Point(blockWidth / 2, blockHeight / 2); }
bool StationaryEnemy::is_dead() { return exists == false; }
void StationaryEnemy::die() { exists = false; }