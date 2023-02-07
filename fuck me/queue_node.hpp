#ifndef __QUEUE_NODE_HPP__
#define __QUEUE_NODE_HPP__

#include "node.hpp"
#include <vector>

class QueueNode : public Node {
public:
    QueueNode(int _id, Node* _right = nullptr, Node* _left = nullptr);
    QueueNode(int _id, std::vector<Player*> _players, Node* _parent = nullptr, Node* _right = nullptr, Node* _left = nullptr);
    ~QueueNode() = default;

    void add_player(Player* player, int node_id) override;
    Node* close_station(int node_id) override;
    std::vector<Player*> get_players() const override;
    Player* get_winner() override;
    void relocate_loser(Player* loser) override;

private:
    std::vector<Player*> players;
};

#endif