#ifndef __ENEMIES_HPP__
#define __ENEMIES_HPP__
#include "stationary_enemy.hpp"
#include "moving_enemy.hpp"
#include "audio.hpp"
#include "rsdl.hpp"
#include <vector>

class SpaceShip;

class Enemies {
public:
    Enemies(Window*);
    void set_music_player(AudioPlayer*);
    void set_window_size(int, int);
    void set_music_space_ship(AudioPlayer*);
    int count_alive();
    bool any_member_is_hitting(); //probably spaceship*
    void update();
    void check_for_hitting_spaceship();
    void add_member(StationaryEnemy);
private:
    Window* win;
    AudioPlayer* musicPlayerPtr;
    std::vector<StationaryEnemy> list;
    SpaceShip* spaceShipPtr;
    int blockWidth, blockHeight;
};

#endif 