#include "enemies.hpp"

int Enemies::count_alive() {
    int alive = 0;
    for (auto& enemy : list) 
        alive += !(enemy.is_dead());
    
    return alive;
}

void Enemies::update() {
    for (auto& enemy : list)
        enemy.update(win);
    
    check_for_hitting_spaceship();
    check_for_getting_hit();
    check_for_collding_with_spaceship();
}

void Enemies::check_for_hitting_spaceship() {
    for (auto& enemy : list) 
        enemy.check_for_hitting_spaceship(spaceShipPtr);
}

void Enemies::check_for_getting_hit() {
    for (auto& enemy : list) 
        if (enemy.check_for_getting_hit(spaceShipPtr))
            musicPlayerPtr->play_sound_effect(EXPLOSION);  
}

void Enemies::check_for_collding_with_spaceship() {
    for (auto& enemy : list)
        enemy.check_for_collding_with_ship(spaceShipPtr);
}

void Enemies::set_window(Window* _win) { win = _win; }
void Enemies::initialise() { list.clear(); }
void Enemies::add_member(StationaryEnemy enemy) { list.push_back(enemy); }
void Enemies::set_block_size(int _blockWidth, int _blockHeight) { blockWidth = _blockWidth; blockHeight = _blockHeight;}
void Enemies::set_music_player(AudioPlayer* _musicPlayerPtr) { musicPlayerPtr = _musicPlayerPtr; }
void Enemies::set_space_ship(SpaceShip* _SpaceShipPtr) { spaceShipPtr = _SpaceShipPtr; }