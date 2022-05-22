#ifndef __DELETE_REQUEST_HPP__
#define __DELETE_REQUEST_HPP__

#include "request.hpp"

class DeleteRequest : public Request {
    virtual void handle(DataBase& database);
};

#endif