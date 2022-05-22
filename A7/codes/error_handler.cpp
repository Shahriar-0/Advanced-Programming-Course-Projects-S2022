#include "error_handler.hpp"

ErrorHandler::ErrorHandler(std::string _message, std::string _detail) : invalid_argument(_message), detail(_detail) {}
void ErrorHandler::show_error() { std::cerr << what() << std::endl; }
void ErrorHandler::show_detail() { std::cerr << detail << std::endl; }