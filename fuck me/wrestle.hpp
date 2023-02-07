#ifndef __WRESTLE_HPP__
#define __WRESTLE_HPP__

#include "game_station.hpp"

class Wrestle : public GameStation {
public:
    Wrestle(int _id, Node* right, Node* left);
    Player* winner_of_match() override;
};

#endif