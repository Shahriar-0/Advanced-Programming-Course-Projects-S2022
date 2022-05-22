#ifndef __REQUEST_HPP__
#define __REQUEST_HPP__
#include "database.hpp"

class Request {
public:
    virtual void handle(DataBase& database);
};

#endif