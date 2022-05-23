#ifndef __REQUEST_HPP__
#define __REQUEST_HPP__
#include "database.hpp"
#include <string>

constexpr char COMMAND_DELIMITER        = ' ';

constexpr int NOT_FOUND_INDEX           = -1;

const std::string EMPTY_STRING          = "";
const std::string USERNAME_KEYWORD      = "username";

class Request {
public:
    Request(std::string line);
    ~Request() = default;
    virtual void handle(DataBase& database) = 0;
protected:
    int find_index(std::string word);
    std::vector<std::string> commands;
    void split_input_line(std::string line);
    std::string username;
};

#endif