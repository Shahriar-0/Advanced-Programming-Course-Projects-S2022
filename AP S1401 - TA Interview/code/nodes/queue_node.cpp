#include "queue_node.hpp"


QueueNode::QueueNode(int _id, Node* _parent = nullptr, Node* _right = nullptr,
            Node* _left = nullptr) : Node(_id, _parent, _right, _left) {}

void QueueNode::add_player(Player* player) { 
    int index = player->get_win();
    
    if (index >= players.size()) 
        players.insert(players.begin(), player);
    else 
        players.insert(players.end() - index, player);
}