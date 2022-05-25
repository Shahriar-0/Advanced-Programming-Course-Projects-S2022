#include "error_handler.hpp"

ErrorHandler::ErrorHandler(std::string _message, std::string _detail) : invalid_argument(_message), detail(_detail) {}
void ErrorHandler::show_error() { std::cout << what() << std::endl; /*show_detail();*/ }   //this is for debugging
void ErrorHandler::show_detail() { std::cout << detail << std::endl; }