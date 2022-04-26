#include "spaceship.hpp"
using namespace std;
SpaceShip::SpaceShip(Window* _win)  : topLeft(Point(rand() % win->get_width(), win->get_height() - 50)) {
    //50 is just a rational random number for
    win = _win;
    health = INITIAL_HEALTH;
}


void SpaceShip::set_move(char move) {
    if (move == 'a' || move == 'A')
        vx = -HORIZONTAL_SPEED;
    else if (move == 'd' || move == 'D') 
        vx = HORIZONTAL_SPEED;
    else if (move == 's' || move == 'S') 
        vy = VERTICAL_SPEED;
    else if (move == 'w' || move == 'W') 
        vy = -VERTICAL_SPEED;
}

void SpaceShip::stop_moving(char move) {
    if (move == 'a' || move == 'A')
        if (vx < 0)
            vx = 0;
    else if (move == 'd' || move == 'D') 
        if (vx > 0)
            vx = 0;
    else if (move == 's' || move == 'S') 
        if (vy > 0)
            vy = 0;
    else if (move == 'w' || move == 'W') 
        if (vy < 0)
            vy = 0;
    else if (move == ' ') 
        shoot();
}

void SpaceShip::shoot() {
    play_shooting_sound();
    bullets.push_back(Bullet(get_center(), blockWidth, blockHeight, MY_SPACESHIP));
}

void SpaceShip::update() {
    update_bullets();
    if (is_dead())
        return;
    move();
    draw();
}

void SpaceShip::update_bullets() {
    for (auto& bullet : bullets) 
        bullet.update(win);
}

void SpaceShip::play_shooting_sound() { musicPlayerPtr->play_sound_effect(SHOOTING); }
void SpaceShip::play_explosion_sound() { musicPlayerPtr->play_sound_effect(EXPLOSION); }
void SpaceShip::die() { exists = false; }
bool SpaceShip::is_dead() { return exists == false; }
void SpaceShip::set_window_size(int _blockWidth, int _blockHeight) { blockWidth = _blockWidth; blockHeight = _blockHeight;}
void SpaceShip::set_music_player(AudioPlayer* _musicPlayerPtr) { musicPlayerPtr = _musicPlayerPtr; }
Point SpaceShip::get_center() { return topLeft + Point(blockWidth, blockHeight); }
void SpaceShip::draw() { win->draw_img(MY_SPACESHIP_PIC, Rectangle(topLeft, blockWidth, blockHeight)); }
vector<Bullet>* SpaceShip::get_bullets() { return &bullets; }

void SpaceShip::move() { 
    topLeft += Point(vx, vy);
    if (topLeft.x < 0) topLeft.x = 0;
    if (topLeft.y < 0) topLeft.y = 0;
    if (topLeft.x > win->get_width()) topLeft.x = win->get_width();
    if (topLeft.x > win->get_height()) topLeft.x = win->get_height();
}


void SpaceShip::get_shot() {
    reduce_health();
    play_explosion_sound();
}

void SpaceShip::reduce_health() {
    health--;
    if (health <= 0) 
        die();
}
