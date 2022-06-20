#ifndef __GET_REQUEST_HPP__
#define __GET_REQUEST_HPP__
#include "request.hpp"

enum GetType { GET_TRIPS, COST };

const std::string getRequestCommands[] = {
    "trips",
    "cost"
};

const std::string SORT_BY_COST_KEYWORD = "sort_by_cost";

class GetRequest : public SystemRequest {
public:
    GetRequest(std::string line);
    virtual void handle(DataBase& database, Response* response, std::string username);

private:
    void check_for_cost_validation();
    void check_for_trips_validation();
    void handle_cost(DataBase& database, Response* response);
    void handle_trips(DataBase& database, Response* response, std::string username);
    void check_for_type();
    std::string originName;
    std::string destinationName;
    GetType type;
    Person* person;
    bool inHurry;
    bool sortByCost;
    int id;
};

#endif