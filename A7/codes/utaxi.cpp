#include "utaxi.hpp"

UTaxi::UTaxi(std::string filename) : IOHandlerVar(filename) {
    IOHandlerVar.read_locations(database);
}