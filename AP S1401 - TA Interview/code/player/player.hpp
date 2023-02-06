#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <string>

class Player {
    public:
        Player(int _id, int _power, int _speed, int _intelligence, std::string main_ability);
        ~Player();
        int get_win();
        int calc_skill();
    private:
        int *main_trait;
        int strength;
        int agility;
        int intelligence;
        int id;
        int win;
};

#endif