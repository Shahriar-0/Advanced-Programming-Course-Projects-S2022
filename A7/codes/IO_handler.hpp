#ifndef __IO_HANDLER_HPP__
#define __IO_HANDLER_HPP__

#include <iostream>
#include <cstring>
#include "database.hpp"


class IOHandler {
public:
    IOHandler(std::string filename);
private:
    std::string filename;
};

#endif