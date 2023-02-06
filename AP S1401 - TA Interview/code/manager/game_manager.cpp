#include "game_manager.hpp"

typedef void (GameManager::*game_manager_method)(std::map<std::string, std::string>);
typedef std::map<std::string, game_manager_method> game_manager_func_map_type;

using namespace std;

GameManager::GameManager(game_manager_func_map_type& func_map) {
    load_nodes();
    
    map_functions(func_map);
}

void GameManager::load_nodes() {
    // Load all nodes from the database
    
}

void GameManager::map_functions(game_manager_func_map_type& func_map) {
    // Map all strings to the function map

    func_map[ARRIVAL_KEYWORD] = &GameManager::add_player;
    func_map[RUN_KEYWORD] = &GameManager::run;
    func_map[END_GAME_KEYWORD] = &GameManager::shutdown;
    func_map[CLOSE_KEYWORD] = &GameManager::close_station;

}
