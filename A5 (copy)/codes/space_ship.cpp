#include "space_ship.hpp"

SpaceShip::SpaceShip(Point _topLeft, Window* _win) : topLeft(_topLeft) { 
    win = _win;
    exists = true;
}

void SpaceShip::move() { 
    topLeft += Point(vx, vy);
    if (topLeft.x < 0) topLeft.x = 0;
    else if (topLeft.x + blockWidth > win->get_width()) topLeft.x = win->get_width() - blockWidth;
    if (topLeft.y < 0) topLeft.y = 0;
    else if (topLeft.y + blockHeight > win->get_height()) topLeft.y = win->get_height() - blockHeight;
}

void SpaceShip::get_shot() {
    reduce_stamina();
    play_explosion_sound();
}

void SpaceShip::reduce_stamina() {
    stamina--;
    if (stamina <= 0)
        die();
}

Point SpaceShip::get_center() const { return topLeft + Point(blockWidth / 2, blockHeight / 2); }
void SpaceShip::play_explosion_sound() { musicPlayerPtr->play_sound_effect(EXPLOSION); }
void SpaceShip::set_block_size(int _blockWidth, int _blockHeight) { blockWidth = _blockWidth; blockHeight = _blockHeight;}
void SpaceShip::set_music_player(AudioPlayer * _musicPlayerPtr) { musicPlayerPtr = _musicPlayerPtr; }
bool SpaceShip::is_dead() const { return exists == false; }
void SpaceShip::die() { exists = false; }