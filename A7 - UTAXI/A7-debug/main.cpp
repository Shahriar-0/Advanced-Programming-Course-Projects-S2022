#include "utaxi.hpp"

int main(int argc, char* argv[]) {
    UTaxi manager("locations.csv");
    manager.run();
}