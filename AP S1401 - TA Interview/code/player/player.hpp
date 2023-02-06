#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <string>

class Player {
    public:
        Player(int _id, int _power, int _speed, int _intelligence, std::string main_ability);
        ~Player();
    private:
        int *main_trait;
        int power;
        int speed;
        int intelligence;
        int id;
        int win;
};

#endif