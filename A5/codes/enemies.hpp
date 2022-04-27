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
    void set_music_player(AudioPlayer*);
    void set_block_size(int, int);
    void set_space_ship(SpaceShip*);
    int count_alive();
    void update();
    void check_for_hitting_spaceship();
    void check_for_getting_hit();
    void check_for_collding_with_spaceship();
    void add_member(StationaryEnemy);
    void initialise();
    void set_window(Window*);
private:
    Window* win;
    AudioPlayer* musicPlayerPtr;
    std::vector<StationaryEnemy> list;
    SpaceShip* spaceShipPtr;
    int blockWidth, blockHeight;
};

#endif 