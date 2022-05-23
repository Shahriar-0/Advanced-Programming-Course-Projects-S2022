#ifndef __POST_REQUEST_HPP__
#define __POST_REQUEST_HPP__

#include "request.hpp"

constexpr int EMPTY_ID                  = 0;

const std::string ROLE_KEYWORD          = "role";
const std::string ID_KEYWORD            = "id";
const std::string DESTINATION_KEYWORD   = "destination";
const std::string ORIGIN_KEYWORD        = "origin";


enum PostType { SIGNUP, ACCEPT, TRIPS, FINISH };


class PostRequest : public Request {

public:
    PostRequest(std::string line, PostType type);
    virtual void handle(DataBase& database);

private:
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