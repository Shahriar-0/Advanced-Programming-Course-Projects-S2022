#ifndef __GAME_STATION_HPP__
#define __GAME_STATION_HPP__

#include "../manager/game_manager.hpp"

class GameStation : public Node {
public:
    GameStation(int _id, Node* _parent = nullptr, Node* _left = nullptr, Node* _right = nullptr);
    ~GameStation() = default;
    void add_player(Player* player, int node_id) override;
    Node* close_station(int node_id) override;
    std::vector<Player*> get_players() const override;
private:
    Player* right_player;
    Player* left_player;
};

#endif