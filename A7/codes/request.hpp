#ifndef __REQUEST_HPP__
#define __REQUEST_HPP__
#include "database.hpp"

constexpr char COMMAND_DELIMITER = ' ';

class Request {
public:
    virtual void handle(DataBase& database);
protected:
    std::vector<std::string> commands;
    void split_input_line(std::string line);
};

#endif