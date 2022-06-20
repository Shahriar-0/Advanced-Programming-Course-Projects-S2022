#include "utaxi.hpp"

UTaxi::UTaxi(std::string filename) : IOHandlerVar(filename) {
    IOHandlerVar.read_locations(database);
}

void UTaxi::run(std::string line, std::string username, Response* response) {
    request = IOHandlerVar.generate_request(line);
    request->handle(database, response);
}