#include "utaxi.hpp"

UTaxi::UTaxi(std::string filename) : IOHandler(filename) {
    IOHandler.read_locations(database);
    database.print_loc();
}