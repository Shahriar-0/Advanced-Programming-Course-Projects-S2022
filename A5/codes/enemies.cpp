#include "enemies.hpp"

Enemies::Enemies(Window* _win) { win = _win; }

int Enemies::count_alive() {
    int alive = 0;
    for (auto& enemy : list) {
        alive += !(enemy.is_dead());
    }
    return alive;
}

void Enemies::update() {
    for (auto& enemy : list) {
        enemy.update(win);
    }
    check_for_hitting_spaceship(SpaceShip*);
    check_for_getting_hit();
}

void Enemies::check_for_hitting_spaceship() {
    for (auto& enemy : list) {
        enemy.check_for_hitting_spaceship();
    }
}

void Enemies::add_member(StationaryEnemy enemy) { list.push_back(enemy); }
void Enemies::set_window_size(int _blockWidth, int _blockHeight) { blockWidth = _blockWidth; blockHeight = _blockHeight;}
void Enemies::set_music_player(AudioPlayer* _musicPlayerPtr) { musicPlayerPtr = _musicPlayerPtr; }
void Enemies::set_music_space_ship(SpaceShip* _SpaceShipPtr) { spaceShipPtr = _SpaceShipPtr; }