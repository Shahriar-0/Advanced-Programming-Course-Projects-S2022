#ifndef __ERROR_HANDLER_HPP__
#define __ERROR_HANDLER_HPP__

#include <iostream>
#include <stdexcept>
#include <cstring>

    // errors list
const std::string NOT_FOUND         = "Not Found";
const std::string BAD_REQUEST       = "Bad Request";
const std::string PERMISSION_DENIED = "Permission Denied";


class ErrorHandler : public std::invalid_argument {
public:
    ErrorHandler(std::string message, std::string detail);
    void show_error();
    std::string get_detail();
    std::string get_page();
private:
    std::string detail;
};

#endif