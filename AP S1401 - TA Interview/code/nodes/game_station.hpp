#ifndef __GAME_STATION_HPP__
#define __GAME_STATION_HPP__

#include "../manager/game_manager.hpp"

class GameStation : public GameManager::Node {
public:
    GameStation(int _id, GameManager::Node* _parent = nullptr, GameManager::Node* _left = nullptr,
            GameManager::Node* _right = nullptr) : GameManager::Node(_id, _parent, _right, _left) {};
    ~GameStation() = default;
    void add_player(GameManager::Player* player) override;
private:
    GameManager::Player* right_player;
    GameManager::Player* left_player;
};

#endif