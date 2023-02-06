#include "../manager/game_manager.hpp"


Node::Node(int _id, Node* _parent, Node* _right, Node* _left) : id(_id), parent(_parent), right(_right), left(_left) {
    if (right != nullptr) right->parent = this;
    if (left != nullptr) left->parent = this;
}
 