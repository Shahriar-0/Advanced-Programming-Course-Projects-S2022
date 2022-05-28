#ifndef __GET_REQUEST_HPP__
#define __GET_REQUEST_HPP__
#include "request.hpp"

const std::string getRequestCommands[] = {
    "trips"
};

class GetRequest : public Request {
public:
    GetRequest(std::string line);
    virtual void handle(DataBase& database);

private:
    void check_for_type();
    int id;
};

#endif