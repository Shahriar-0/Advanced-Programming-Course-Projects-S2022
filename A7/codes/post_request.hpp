#ifndef __POST_REQUEST_HPP__
#define __POST_REQUEST_HPP__

#include "request.hpp"

enum PostType { SIGNUP, ACCEPT, TRIPS, FINISH };

constexpr int NOT_FOUND_INDEX = -1;

class PostRequest : public Request {
public:
    PostRequest(std::string line, PostType type);
    virtual void handle(DataBase& database);
private:
    void split_input_line(std::string line);
    void check_for_signup_validation();
    void check_for_accept_validation();
    void check_for_finish_validation();
    void check_for_trips_validation();
    int find_index(std::string word);
    PostType type;
    std::string username;
    std::string origin;
    std::string destination;
    std::string role;
    int id;
};

#endif