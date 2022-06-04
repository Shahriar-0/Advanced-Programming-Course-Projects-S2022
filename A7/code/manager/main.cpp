#include "utaxi.hpp"

int main(int argc, char* argv[]) {
    UTaxi manager(argv[1]);
    manager.run();
}