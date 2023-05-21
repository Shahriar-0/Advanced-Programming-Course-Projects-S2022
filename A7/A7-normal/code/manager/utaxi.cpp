#include "utaxi.hpp"

UTaxi::UTaxi(std::string filename) : IOHandlerVar(filename) {
    IOHandlerVar.read_locations(database);
}

void UTaxi::run() {
    std::string line;
    while (getline(std::cin, line)) {
        try {
            request = IOHandlerVar.generate_request(line);
            request->handle(database);
            delete request;
        }
        catch(ErrorHandler& error) {
            error.show_error();
        }
    }
}