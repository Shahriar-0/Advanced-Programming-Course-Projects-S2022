#ifndef __NODE_HPP__
#define __NODE_HPP__

#include "../player/player.hpp"
#include <stdexcept>
#include <exception>
#include <vector>

class Node {
public:
    Node(int _id, Node* _right = nullptr, Node* _left = nullptr);
    ~Node() = default;

    bool is_root();
    int get_id();
    void shutdown();
    
    virtual void add_player(Player* player, int node_id) = 0;
    virtual Node* close_station(int node_id) = 0;
    virtual std::vector<Player*> get_players() const = 0;
    virtual Player* get_winner() = 0;
    virtual void relocate_loser(Player* loser) = 0;

protected:
    int id;
    Node* right;
    Node* left;
    Node* parent;
};

#endif