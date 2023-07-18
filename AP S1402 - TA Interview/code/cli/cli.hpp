#ifndef __CLI_HPP__
#define __CLI_HPP__

#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "../manager/game_manager.hpp"

// consts
constexpr char INPUT_DELIMETER = ' ';
const std::string RUN_KEYWORD = "Run";
const std::string END_GAME_KEYWORD = "$";
const std::string CLOSE_KEYWORD = "Close";
const std::string ARRIVAL_KEYWORD = "Arrival";

typedef void (GameManager::*game_manager_method)(std::vector<std::string>);
typedef std::map<std::string, game_manager_method> game_manager_func_map_type;

class CLI {
   public:
    CLI();
    std::vector<std::string> split_input_by_delimeter(std::string input, char delimeter = INPUT_DELIMETER);
    void run();

   private:
    void map_functions();
    GameManager game_manager;
    game_manager_func_map_type game_manager_func_map;
};

#endif