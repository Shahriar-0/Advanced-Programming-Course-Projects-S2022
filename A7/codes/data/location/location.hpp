#ifndef __LOCATION_HPP__
#define __LOCATION_HPP__

#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include "../error/error_handler.hpp"

class Location {
public:
    Location() = default;
    Location(std::string name, int latitude, int longitude);
    bool operator==(std::string name) const;
    friend std::ifstream& operator>>(std::ifstream& stream, Location& location);
    friend std::ostream& operator<<(std::ostream& stream, Location& location);
private:
    int latitude, longitude;
    std::string name;
};

#endif