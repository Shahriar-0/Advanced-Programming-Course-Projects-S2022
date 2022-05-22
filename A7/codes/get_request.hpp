#ifndef __GET_REQUEST_HPP__
#define __GET_REQUEST_HPP__

#include "request.hpp"

class GetRequest : public Request {
    virtual void handle(DataBase& database);
};

#endif