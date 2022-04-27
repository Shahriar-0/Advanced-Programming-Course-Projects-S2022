#include "stationary_enemy.hpp"
using namespace std;


StationaryEnemy::StationaryEnemy(Point _topLeft, int _blockWidth, int _blockHeight) : topLeft(_topLeft) { 
    frameCounter = rand() % FRAME_LIMIT;
    blockWidth = _blockWidth;
    blockHeight = _blockHeight;
}
StationaryEnemy::StationaryEnemy() : topLeft(Point(0, 0)) {}
//this is just to avoid the problem that occurs when calling the constructor of MovingEnemy which
//is a subclass of this class, and I'm not sure why this happens.


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
    vector<Bullet>* spaceShipBulletsPtr = spaceShipPtr->get_bullets();
    for (auto& bullet : *spaceShipBulletsPtr) {
        if (bullet.is_colliding(get_center())) {
            die();
            bullet.extinct();
            return true;
        }
    }
    return false;
}

void StationaryEnemy::check_for_collding_with_ship(SpaceShip* spaceShipPtr) {
    if (are_colliding(spaceShipPtr->get_center())) {
        spaceShipPtr->die();
        spaceShipPtr->play_explosion_sound();
        die();
    }
}

bool StationaryEnemy::are_colliding(Point target) { return (abs(get_center().x - target.x) < COLLISION_RANGE && abs(get_center().y - target.y) < COLLISION_RANGE); }
Point StationaryEnemy::get_center() { return topLeft + Point(blockWidth / 2, blockHeight / 2); }
bool StationaryEnemy::is_dead() { return exists == false; }
void StationaryEnemy::die() { exists = false; }
void StationaryEnemy::draw(Window* win) { win->draw_img(STATIONARY_ENEMY_PIC, Rectangle(topLeft, blockWidth, blockHeight)); }