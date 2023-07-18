#include "game_manager.hpp"

#include "../cli/cli.hpp"

typedef void (GameManager::*game_manager_method)(std::vector<std::string>);
typedef std::map<std::string, game_manager_method> game_manager_func_map_type;

using namespace std;

GameManager::GameManager() : is_working(true) {
    load_nodes();
}

enum LoadStation {
    ID_INDEX,
    LEFT_INDEX,
    RIGHT_INDEX,
    TYPE_INDEX
};

void GameManager::load_nodes() {
    string line;
    int num_nodes, i;
    getline(cin, line);
    i = num_nodes = stoi(line);
    vector<Node*> nodes;
    while (i--) {
        getline(cin, line);
        add_node(line, nodes, num_nodes);
    }
    root_node = *find_if(nodes.begin(), nodes.end(), [](Node* node) { return node->is_root(); });
}

void GameManager::split_line(int& node_id, int& right_node_id, int& left_node_id, string& type, string& line) {
    node_id = stoi(line.substr(0, line.find(' ')));
    line = line.substr(line.find(' ') + 1);
    left_node_id = stoi(line.substr(0, line.find(' ')));
    line = line.substr(line.find(' ') + 1);
    right_node_id = stoi(line.substr(0, line.find(' ')));
    line = line.substr(line.find(' ') + 1);
    type = line.substr(0, line.find(' '));
}

void GameManager::find_left_and_right(Node*& left_node, Node*& right_node, vector<Node*>& nodes,
                                      int left_node_id, int right_node_id) {
    auto right_node_it = find_if(nodes.begin(), nodes.end(),
                                 [&nodes, &right_node_id](Node*& node) { return node->get_id() == right_node_id; });

    auto left_node_it = find_if(nodes.begin(), nodes.end(),
                                [&nodes, &left_node_id](Node*& node) { return node->get_id() == left_node_id; });

    bool right_node_exists = (right_node_it != nodes.end());
    bool left_node_exists = (left_node_it != nodes.end());
    // cause i need to push back the .end will changed

    if (right_node_exists)
        right_node = *right_node_it;
    else {
        right_node = createInstance<QueueNode>(right_node_id, nullptr, nullptr);
        nodes.push_back(right_node);
    }

    if (left_node_exists)
        left_node = *left_node_it;
    else {
        left_node = createInstance<QueueNode>(left_node_id, nullptr, nullptr);
        nodes.push_back(left_node);
    }
}

void GameManager::add_node(string line, vector<Node*>& nodes, int num_nodes) {
    // Add a node to the nodes vector and to the tree
    int node_id, right_node_id, left_node_id;
    string type;
    split_line(node_id, right_node_id, left_node_id, type, line);

    Node* left_node = nullptr;
    Node* right_node = nullptr;
    find_left_and_right(left_node, right_node, nodes, left_node_id, right_node_id);

    Node* node;
    if (node_id > num_nodes)
        node = createInstance<QueueNode>(node_id, right_node, left_node);

    else {
        if (type == CHESS_KEYWORD)
            node = createInstance<Chess>(node_id, right_node, left_node);
        else if (type == WRESTLE_KEYWORD)
            node = createInstance<Wrestle>(node_id, right_node, left_node);
        else if (type == ARMWRESTLE_KEYWORD)
            node = createInstance<ArmWrestle>(node_id, right_node, left_node);
        else if (type == KABAB_KEYWORD)
            node = createInstance<Kabab>(node_id, right_node, left_node);
        else
            throw logic_error("Invalid node type");
    }
    nodes.push_back(node);
}

void GameManager::run(std::vector<std::string> args) {
    Player* winner = root_node->get_winner();
    if (winner != nullptr)
        cout << *winner << endl;
    else
        cout << "No winner" << endl;
}

enum Close {  // indexes of the arguments in the close station command
    CLOSE_KEYWORD_INDEX,
    QUEUE_INDEX_CLOSE,
};

void GameManager::close_station(std::vector<std::string> args) {
    root_node = root_node->close_station(stoi(args[Close::QUEUE_INDEX_CLOSE]));
}

enum Arrival {  // indexes of the arguments in the arrival command
    ARRIVAL_KEYWORD_INDEX,
    QUEUE_INDEX_ARRIVAL,
    PLAYER_INDEX,
    STRENGTH_INDEX,
    AGILITY_INDEX,
    INTELLIGENCE_INDEX,
    MAIN_ABILITY_INDEX
};

void GameManager::add_player(std::vector<std::string> args) {
    Player* player = new Player(stoi(args[PLAYER_INDEX]), stoi(args[STRENGTH_INDEX]),
                                stoi(args[AGILITY_INDEX]), stoi(args[INTELLIGENCE_INDEX]), args[MAIN_ABILITY_INDEX]);
    root_node->add_player(player, stoi(args[Arrival::QUEUE_INDEX_ARRIVAL]));
}

void GameManager::shutdown(std::vector<std::string> args) {
    // root_node->shutdown(); // TODO: implement shutdown
    is_working = false;
}

template <typename T>
T* GameManager::createInstance(int _id, Node* right, Node* left) {
    // Create a new instance of a specific type of node with the given parameters
    return new T(_id, right, left);
}

bool GameManager::is_running() { return is_working; }