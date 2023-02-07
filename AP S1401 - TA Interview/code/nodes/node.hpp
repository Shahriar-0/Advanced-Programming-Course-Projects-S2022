#ifndef __NODE_HPP__
#define __NODE_HPP__

#include "../player/player.hpp"
#include <stdexcept>
#include <exception>

class Node {
    public:
        Node(int _id, Node* _right = nullptr, Node* _left = nullptr);
        ~Node() = default;
        virtual void add_player(Player* player, int node_id) = 0;
        virtual Node* close_station(int node_id) = 0;
        bool is_root() { return parent == nullptr; }
        virtual std::vector<Player*> get_players() const = 0;
    protected:
        int id;
        Node* right;
        Node* left;
        Node* parent;
};

#endif