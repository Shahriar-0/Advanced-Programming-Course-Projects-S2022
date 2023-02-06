#include "queue_node.hpp"

using namespace std;


QueueNode::QueueNode(int _id, Node* _parent = nullptr, Node* _right = nullptr,
            Node* _left = nullptr) : Node(_id, _parent, _right, _left) {}

void QueueNode::add_player(Player* player, int node_id) { 
    if (node_id == id) {
        int index = player->get_win();

        if (index >= players.size()) 
            players.insert(players.begin(), player);
        else 
            players.insert(players.end() - index, player);
        
        return;
    }
    // since this is a queue, we aren't suppose to have right and left nodes
}

Node* QueueNode::close_station(int node_id) {
    if (node_id == id) 
        throw runtime_error("Cannot close a queue station");
    return nullptr; // since this is a queue, we aren't suppose to have right and left nodes
}