#ifndef __POST_REQUEST_HPP__
#define __POST_REQUEST_HPP__

#include "request.hpp"

const std::string ROLE_KEYWORD          = "role";



enum PostType { SIGNUP, ACCEPT, POST_TRIPS, FINISH };

const std::string postRequestCommands[] = {
    "signup",
    "accept",
    "trips",
    "finish"
};

class PostRequest : public SystemRequest {
public:
    PostRequest(std::string line);
    virtual void handle(DataBase& database);

private:
    void handle_signup(DataBase& database);
    void handle_trips(DataBase& database);
    void handle_accept(DataBase& database);
    void handle_finish(DataBase& database);
    void check_for_type();
    void check_for_signup_validation();
    void check_for_finish_and_accept_validation();
    void check_for_trips_validation();
    
    PostType type;
    std::string origin;
    std::string destination;
    std::string role;
    Person* person;
    Trip* trip;
    int id;
    bool inHurry;
};

#endif