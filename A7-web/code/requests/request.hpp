#ifndef __REQUEST_HPP__
#define __REQUEST_HPP__
#include "../datas/database.hpp"
#include <map>
#include <utility>
#include <string>

constexpr char COMMAND_DELIMITER        = ' ';

constexpr int EMPTY_ID                  = 0;
constexpr int NOT_FOUND_INDEX           = -1;

const std::string EMPTY_STRING          = "";
const std::string ID_KEYWORD            = "id";
const std::string USERNAME_KEYWORD      = "username";
const std::string DESTINATION_KEYWORD   = "destination";
const std::string ORIGIN_KEYWORD        = "origin";
const std::string IN_HURRY_KEYWORD      = "in_hurry";
const std::string AGREE                 = "yes";
const std::string DISAGREE              = "no";

class Request {
public:
    Request(std::string line);
    ~Request() = default;
    virtual void handle(DataBase& database) = 0;
protected:
    int find_index(std::string word);
    std::vector<std::string> commands;
    void split_input_line(std::string line);
    std::string username;   //this variable holds the username of the person who has submitted this request
};

#endif