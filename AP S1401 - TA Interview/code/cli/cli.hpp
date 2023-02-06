#ifndef __CLI_HPP__
#define __CLI_HPP__

#include "../manager/game_manager.hpp"
#include <string>
#include <vector>
#include <sstream>
#include <map>

// consts
constexpr char INPUT_DELIMETER = ' ';
const std::string RUN_KEYWORD = "run";
const std::string END_GAME_KEYWORD = "$";
const std::string CLOSE_KEYWORD = "close";
const std::string ARRIVAL_KEYWORD = "arrival";



class CLI {
public:
    CLI();
    std::vector<std::string> split_input_by_delimeter(std::string input, char delimeter = INPUT_DELIMETER);
    void run();
private:
    GameManager game_manager;
    game_manager_func_map_type game_manager_func_map;
};

#endif