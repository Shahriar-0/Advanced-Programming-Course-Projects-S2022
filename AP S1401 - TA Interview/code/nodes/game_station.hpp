#ifndef __GAME_STATION_HPP__
#define __GAME_STATION_HPP__

#include "../manager/game_manager.hpp"
#include <cmath>

class GameStation : public Node {
public:
    GameStation(int _id, Node* _left = nullptr, Node* _right = nullptr);
    ~GameStation() = default;

    virtual Player* winner_of_match() = 0;

    void add_player(Player* player, int node_id) override;
    Node* close_station(int node_id) override;
    std::vector<Player*> get_players() const override;
    Player* get_winner() override;
    void relocate_loser(Player* loser) override;
    
    std::vector<Player*> combine_lists();
    Player* determine_winner();
protected:
    Player* right_player;
    Player* left_player;
};

#endif