#include "moving_enemies.hpp"

MovingEnemies::MovingEnemies(Window* _win, AudioPlayer* _musicPlayerptr, SpaceShip* _ptrToShip) {
    win = _win;
    musicPlayerptr = _musicPlayerptr;
    ptrToShip = _ptrToShip;
}

int MovingEnemies::count_alive() {
    int num = 0;
    for (auto i : list)
        num += (!i.is_dead());
    return num;
}