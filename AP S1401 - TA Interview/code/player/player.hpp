#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <string>
#include <math.h>
#include "../manager/game_manager.hpp"

class Player {
public:
    Player(int _id, int _power, int _speed, int _intelligence, std::string main_ability);
    ~Player() = default;
    int get_win();
    int calc_skill();
    void update_stats();
    double calc_chess_power();
    double calc_wrestle_power();
    double calc_arm_wrestle_power();
    double calc_kabab_power();

private:
    int *main_trait;
    int strength;
    int agility;
    int intelligence;
    int id;
    int win;
};

#endif