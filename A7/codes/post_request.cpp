#include "post_request.hpp"

PostRequest::PostRequest(std::string _line, PostType _type) : type(_type) {
    Request::split_input_line(_line);
    if (type == ACCEPT)
        check_for_accept_validation();
    if (type == FINISH)
        check_for_finish_validation();
    if (type == TRIPS)
        check_for_trips_validation();
    if (type == SIGNUP)
        check_for_signup_validation();
}

int PostRequest::find_index(std::string word) {
    for (int i = 0; i < commands.size() - 1; i++) 
        if (commands[i] == word)
            return i + 1;
    return NOT_FOUND_INDEX;
}

void PostRequest::check_for_accept_validation() {
    int usernameIndex = find_index("username");
    int roleIndex = find_index("role");
    if (usernameIndex == NOT_FOUND_INDEX || roleIndex == NOT_FOUND_INDEX)
        throw ErrorHandler(BAD_REQUEST, "username or role not found");
    
}

void PostRequest::handle(DataBase& database) {
    
}

void PostRequest::check_for_finish_validation() {

}

void PostRequest::check_for_trips_validation() {

}

void PostRequest::check_for_signup_validation() {

}