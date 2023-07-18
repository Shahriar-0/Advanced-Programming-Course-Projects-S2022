#include "game_station.hpp"

#include "queue_node.hpp"

using namespace std;

GameStation::GameStation(int _id, Node* _left, Node* _right)
    : Node(_id, _right, _left), right_player(nullptr), left_player(nullptr) {}

void GameStation::add_player(Player* player, int node_id) {
    if (node_id == id)
        throw std::runtime_error("Cannot add player to a game station");
    if (right)
        right->add_player(player, node_id);
    if (left)
        left->add_player(player, node_id);
}

vector<Player*> GameStation::combine_lists() {
    std::vector<Player*> v1{};
    if (right)
        v1 = right->get_players();
    std::vector<Player*> v2{};
    if (left)
        v2 = left->get_players();

    v1.insert(v1.end(), v2.begin(), v2.end());
    sort(v1.begin(), v1.end(), [](Player* p1, Player* p2) { return p1->calc_skill() > p2->calc_skill(); });
    return v1;
}

Node* GameStation::close_station(int node_id) {
    if (node_id == id) {
        std::vector<Player*> v = combine_lists();
        return new QueueNode(node_id, v, parent, right, left);
    }
    if (right) {
        Node* updated_right = right->close_station(node_id);
        if (updated_right != right)
            delete right;  // delete the old right node to avoid memory leak
        right = updated_right;
    }
    if (left) {
        Node* updated_left = left->close_station(node_id);
        if (updated_left != left)
            delete left;  // delete the old left node to avoid memory leak
        left = updated_left;
    }
    return this;
}

Player* GameStation::determine_winner() {
    if (!right_player)
        return left_player;
    if (!left_player)
        return right_player;
    return this->winner_of_match();
}

Player* GameStation::get_winner() {
    right_player = right ? right->get_winner() : nullptr;
    left_player = left ? left->get_winner() : nullptr;
    Player* winner = determine_winner();

    if (winner == right_player)
        left->relocate_loser(left_player);
    else
        left->relocate_loser(right_player);  // cause we move the loser the the leftmost queue

    right_player = left_player = nullptr;

    if (winner)
        winner->update_stats_after_win();

    return winner;
};

void GameStation::relocate_loser(Player* loser) {
    if (left)
        left->relocate_loser(loser);
    else
        throw runtime_error("Cannot relocate loser to a game station");
};

std::vector<Player*> GameStation::get_players() const { throw runtime_error("Cannot get players from a game station"); }