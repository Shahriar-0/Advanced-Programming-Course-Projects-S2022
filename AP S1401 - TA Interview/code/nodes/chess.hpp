#ifndef __CHESS_HPP__
#define __CHESS_HPP__

#include "game_station.hpp"

class Chess : public GameStation {
public:
    Chess(int _id, Node* right, Node* left);
    Player* winner_of_match() override;
};

#endif