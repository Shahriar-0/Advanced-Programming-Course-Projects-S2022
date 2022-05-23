#ifndef __DELETE_REQUEST_HPP__
#define __DELETE_REQUEST_HPP__

#include "request.hpp"

class DeleteRequest : public Request {
public:
    DeleteRequest(std::string _line);
    virtual void handle(DataBase& database);

private:
    int id;    
};

#endif