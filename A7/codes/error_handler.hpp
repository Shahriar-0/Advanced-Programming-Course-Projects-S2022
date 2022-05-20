#ifndef __ERROR_HANDLER_HPP__
#define __ERROR_HANDLER_HPP__

#include <iostream>
#include <stdexcept>
#include <cstring>

class ErrorHandler : public std::invalid_argument {
public:
    ErrorHandler(std::string message, std::string detail);
    void show_error();
private:
    std::string detail;
};

#endif