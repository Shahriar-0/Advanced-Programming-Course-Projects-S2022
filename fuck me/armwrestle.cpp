#include "armwrestle.hpp"

using namespace std;

ArmWrestle::ArmWrestle(int _id, Node* _left, Node* _right) 
          :GameStation(_id, _right, _left) {}

Player* ArmWrestle::winner_of_match() { 
    if (right_player->calc_skill() >= left_player->calc_skill()) // = is for ties and right has priority over left
        return right_player;
    return left_player;
}