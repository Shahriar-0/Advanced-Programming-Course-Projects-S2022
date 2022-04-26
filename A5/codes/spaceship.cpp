#include "spaceship.hpp"

SpaceShip::SpaceShip(Window* _win)  : center(Point(rand() % win->get_width(), win->get_height() - 50)) {
    //50 is just a rational random number for
    win = _win;
    health = INITIAL_HEALTH;
}


void SpaceShip::set_move(char move) {
    if (move == 'a')
}

void SpaceShip::die() { exists = false; }
bool SpaceShip::is_dead() { return exists == false; }
void SpaceShip::set_window_size(int _blockWidth, int _blockHeight) { blockWidth = _blockWidth; blockHeight = _blockHeight;}
void SpaceShip::set_music_player(AudioPlayer* _musicPlayerPtr) { musicPlayerPtr = _musicPlayerPtr; }
void SpaceShip::get_center() { return center; }
void SpaceShip::reduce_health() {
    health--;
    if (health <= 0) 
        die();
}
void SpaceShip::draw() { win->draw_img(MY_SPACESHIP_PIC, Rectangle(topLeft, blockWidth, blockHeight)); }