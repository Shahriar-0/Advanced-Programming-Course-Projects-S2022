#include "chess.hpp"

using namespace std;

Chess::Chess(int _id, Node* _left, Node* _right) 
      :GameStation(_id, _right, _left) {}

Player* Chess::winner_of_match() {
    if (right_player->calc_chess_power() >= left_player->calc_chess_power()) // = is for ties and right has priority over left
        return right_player;
    return left_player;
}