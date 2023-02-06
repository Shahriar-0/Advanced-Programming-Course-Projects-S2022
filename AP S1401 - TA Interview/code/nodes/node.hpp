#ifndef __NODE_HPP__
#define __NODE_HPP__

#include "../player/player.hpp"

class Node {
    public:
        Node(int _id, Node* _parent = nullptr, Node* _right = nullptr,
            Node* _left = nullptr) : id(_id), parent(_parent), right(_right), left(_left) {};
        ~Node() = default;
        virtual void add_player(Player* player) = 0;
    protected:
        int id;
        Node* right;
        Node* left;
        Node* parent;
};

#endif