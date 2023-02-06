#ifndef __GAME_STATION_HPP__
#define __GAME_STATION_HPP__

#include "../manager/game_manager.hpp"

class GameStation : public Node {
public:
    GameStation(int _id, Node* _parent = nullptr, Node* _left = nullptr,
            Node* _right = nullptr) : Node(_id, _parent, _right, _left) {};
    ~GameStation() = default;
    void add_player(Player* player) override;
private:
    Player* right_player;
    Player* left_player;
};

#endif