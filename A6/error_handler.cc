#include "error_handler.hh"

void ErrorHandler::show_error(ErrorType error) { 
    std::cout << errorMassages[error] << std::endl; 
    std::exit(EXIT_SUCCESS);
}