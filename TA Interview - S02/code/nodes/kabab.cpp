#include "kabab.hpp"

using namespace std;

Kabab::Kabab(int _id, Node* _left, Node* _right) 
      :GameStation(_id, _right, _left) {}

Player* Kabab::winner_of_match() {
    if (right_player->calc_kabab_power() >= left_player->calc_kabab_power()) // = is for ties and right has priority over left
        return right_player;
    return left_player;
}