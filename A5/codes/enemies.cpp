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
}

void Enemies::set_window_size(int _blockWidth, int _blockHeight) { blockWidth = _blockWidth; blockHeight = _blockHeight;}
void Enemies::set_music_player(AudioPlayer* _musicPlayerPtr) { musicPlayerPtr = _musicPlayerPtr; }
void Enemies::set_music_space_ship(AudioPlayer* _SpaceShipPtr) { spaceShipPtr = _SpaceShipPtr; }