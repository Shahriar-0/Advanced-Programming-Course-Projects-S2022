#include "game_station.hpp"

using namespace std;

GameStation::GameStation(int _id, Node* _parent, Node* _left, Node* _right) 
    : Node(_id, _parent, _right, _left), right_player(nullptr), left_player(nullptr) {}


void GameStation::add_player(Player* player, int node_id) {
    if (node_id == id) 
        throw std::runtime_error("Cannot add player to a game station");
    if (right)
        right->add_player(player, node_id);
    if (left)
        left->add_player(player, node_id);
}

Node* GameStation::close_station(int node_id) {
    if (node_id == id) {
        std::vector<Player*> v1 {};
        if (right) 
            v1 = right->get_players();
        std::vector<Player*> v2 {};
        if (left) 
            v2 = left->get_players();

        v1.insert(v1.end(), v2.begin(), v2.end());
        sort(v1.begin(), v1.end(), [](Player* p1, Player* p2) { return p1->calc_skill() < p2->calc_skill(); });
        Node* node = new QueueNode(node_id, v1, parent, right, left);
        return node;
    }
    if (right)
        right = right->close_station(node_id);
    if (left)
        left = left->close_station(node_id);
    return this;
}


std::vector<Player*> GameStation::get_players() const {
    throw runtime_error("Cannot get players from a game station");
}