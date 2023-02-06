#include "game_station.hpp"

void GameStation::add_player(Player* player, int node_id) {
    if (node_id == id) 
        throw std::runtime_error("Cannot add player to a game station");
    if (right)
        right->add_player(player, node_id);
    if (left)
        left->add_player(player, node_id);
}

GameStation::GameStation(int _id, Node* _parent, Node* _left, Node* _right) 
    : Node(_id, _parent, _right, _left), right_player(nullptr), left_player(nullptr) {}