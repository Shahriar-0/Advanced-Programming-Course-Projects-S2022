#ifndef __LOCATION_HPP__
#define __LOCATION_HPP__

#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include "../error/error_handler.hpp"

constexpr char FILE_DELIMITER = ',';

class Location {
public:
    Location() = default;
    Location(std::string name, int latitude, int longitude);
    bool operator==(std::string name) const;
    friend void operator>>(std::string& stream, Location& location);
    friend std::ostream& operator<<(std::ostream& stream, Location& location);
private:
    double latitude, longitude;
    std::string name;
};

#endif