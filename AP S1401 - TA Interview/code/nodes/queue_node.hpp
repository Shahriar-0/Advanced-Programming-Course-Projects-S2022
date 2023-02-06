#ifndef __QUEUE_NODE_HPP__
#define __QUEUE_NODE_HPP__

#include "../manager/game_manager.hpp"
#include <vector>

class QueueNode : public GameManager::Node {
public:
    QueueNode(int _id, GameManager::Node* _parent = nullptr, GameManager::Node* _right = nullptr,
            GameManager::Node* _left = nullptr);
    ~QueueNode() = default;
    void add_player(GameManager::Player* player) override;
private:
    std::vector<GameManager::Player*> players;
};

#endif