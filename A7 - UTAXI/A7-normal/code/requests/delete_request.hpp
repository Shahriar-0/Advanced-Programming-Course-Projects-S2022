#ifndef __DELETE_REQUEST_HPP__
#define __DELETE_REQUEST_HPP__

#include "request.hpp"

const std::string DeleteRequestCommands[] = {
    "trips"
};

class DeleteRequest : public Request {
public:
    DeleteRequest(std::string _line);
    virtual void handle(DataBase& database);

private:
    void check_for_type();
    int id;    
};

#endif