#ifndef __POST_REQUEST_HPP__
#define __POST_REQUEST_HPP__

#include "request.hpp"

const std::string ROLE_KEYWORD          = "role";
const std::string DESTINATION_KEYWORD   = "destination";
const std::string ORIGIN_KEYWORD        = "origin";


enum PostType { SIGNUP, ACCEPT, TRIPS, FINISH };

const std::string postRequestCommands[] = {
    "signup"
    "accept",
    "trips",
    "finish",
};

class PostRequest : public Request {
public:
    PostRequest(std::string line);
    virtual void handle(DataBase& database);

private:
    void check_for_type();
    void check_for_signup_validation();
    void check_for_finish_and_accept_validation();
    void check_for_trips_validation();
    
    PostType type;
    std::string username;
    std::string origin;
    std::string destination;
    std::string role;
    int id;
};

#endif