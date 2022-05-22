#ifndef __POST_REQUEST_HPP__
#define __POST_REQUEST_HPP__

#include "request.hpp"

class PostRequest : public Request {
    virtual void handle(DataBase& database);
};

#endif