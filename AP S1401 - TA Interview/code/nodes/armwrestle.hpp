#ifndef __ARMWRESTLE_HPP__
#define __ARMWRESTLE_HPP__

#include "game_station.hpp"

class ArmWrestle : public GameStation {
public:
    ArmWrestle(int _id, Node* right, Node* left);
    Player* winner_of_match() override;
};

#endif