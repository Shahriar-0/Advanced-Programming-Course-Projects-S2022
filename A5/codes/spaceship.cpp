#include "spaceship.hpp"

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
    bullets.push_back(Bullet(get_center(), blockWidth, blockHeight));
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

void SpaceShip::die() { exists = false; }
bool SpaceShip::is_dead() { return exists == false; }
void SpaceShip::set_window_size(int _blockWidth, int _blockHeight) { blockWidth = _blockWidth; blockHeight = _blockHeight;}
void SpaceShip::set_music_player(AudioPlayer* _musicPlayerPtr) { musicPlayerPtr = _musicPlayerPtr; }
Point SpaceShip::get_center() { return topLeft + Point(blockWidth, blockHeight); }
void SpaceShip::draw() { win->draw_img(MY_SPACESHIP_PIC, Rectangle(topLeft, blockWidth, blockHeight)); }
void SpaceShip::reduce_health() {
    health--;
    if (health <= 0) 
        die();
}
