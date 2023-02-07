#ifndef __KABAB_HPP__
#define __KABAB_HPP__

#include "game_station.hpp"

class Kabab : public GameStation {
public:
    Kabab(int _id, Node* _right, Node* _left);
    Player* winner_of_match() override;

};

#endif