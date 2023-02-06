#include "queue_node.hpp"


QueueNode::QueueNode(int _id, GameManager::Node* _parent = nullptr, GameManager::Node* _right = nullptr,
            GameManager::Node* _left = nullptr) : GameManager::Node(_id, _parent, _right, _left) {}

void QueueNode::add_player(GameManager::Player* player) { players.push_back(player); }