#ifndef __GET_REQUEST_HPP__
#define __GET_REQUEST_HPP__

#include "request.hpp"

class GetRequest : public Request {
public:
    GetRequest(std::string line);
    virtual void handle(DataBase& database);

private:
    int id;
};

#endif