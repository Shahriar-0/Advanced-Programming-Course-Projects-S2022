#ifndef __GAME_MANAGER_HPP__
#define __GAME_MANAGER_HPP__

#include <string>
#include <map>
#include <functional>

// typedef void (GameManager::*game_manager_method)(std::map<std::string, std::string>);
// typedef std::map<std::string, game_manager_method> game_manager_func_map_type;
// typedef std::map<std::string, std::function<void(std::map<std::string, std::string>)>> game_manager_func_map_type;

typedef void (GameManager::*game_manager_method)(std::map<std::string, std::string>);
typedef std::map<std::string, game_manager_method> game_manager_func_map_type;


const std::string RUN_KEYWORD = "run";
const std::string END_GAME_KEYWORD = "$";
const std::string CLOSE_KEYWORD = "close";
const std::string ARRIVAL_KEYWORD = "arrival";

class GameManager {
public:
    GameManager(game_manager_func_map_type& game_manager_function_map);
    ~GameManager();

    void run(std::map<std::string, std::string> args);
    void close_station(std::map<std::string, std::string> args);
    void add_player(std::map<std::string, std::string> args);
    void shutdown(std::map<std::string, std::string> args);

    class Node {
    public:
        Node();
        ~Node();
    };

    class Player {
    public:
        Player();
        ~Player();
    };

private:
    void load_nodes();
    void map_functions(game_manager_func_map_type& game_manager_function_map);
    Node* root_node;

};



#endif