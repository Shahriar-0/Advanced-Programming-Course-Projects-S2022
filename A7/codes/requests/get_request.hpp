#ifndef __GET_REQUEST_HPP__
#define __GET_REQUEST_HPP__
#include "request.hpp"

enum GetType { TRIPS, COST };

const std::string getRequestCommands[] = {
    "trips",
    "cost"
};


class GetRequest : public Request {
public:
    GetRequest(std::string line);
    virtual void handle(DataBase& database);
    void check_for_cost_validation();

private:
    void handle_cost(DataBase& database);
    void handle_trips(DataBase& database);
    void check_for_type();
    std::string originName;
    std::string destinationName;
    GetType type;
    Person* person;
    bool inHurry = false;
    int id;
};

#endif