#include "queue_node.hpp"

using namespace std;


QueueNode::QueueNode(int _id, Node* _right, Node* _left) 
          : Node(_id, _right, _left) {}

QueueNode::QueueNode(int _id, std::vector<Player*> _players, Node* _parent, Node* _right, Node* _left) 
          : Node(_id, _right, _left), players(_players) { parent = _parent; }

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