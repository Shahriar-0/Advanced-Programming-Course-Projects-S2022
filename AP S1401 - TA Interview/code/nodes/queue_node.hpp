#ifndef __QUEUE_NODE_HPP__
#define __QUEUE_NODE_HPP__

#include "node.hpp"
#include <vector>

class QueueNode : public Node {
public:
    QueueNode(int _id, Node* _parent = nullptr, Node* _right = nullptr, Node* _left = nullptr);
    ~QueueNode() = default;
    void add_player(Player* player, int node_id) override;
    Node* close_station(int node_id) override;

private:
    std::vector<Player*> players;
};

#endif