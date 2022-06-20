#ifndef __LOCATION_HPP__
#define __LOCATION_HPP__

#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include "../error/error_handler.hpp"

constexpr char FILE_DELIMITER        = ',';
constexpr double EUCLIDEAN_CONVERTER = 110.5;

class Location {
public:
    Location() = default;
    Location(std::string name, int latitude, int longitude);
    bool operator==(std::string name) const;
    int get_traffic_coefficient() const;
    double operator-(const Location& other) const;
    friend void operator>>(std::string& stream, Location& location);
    friend std::ostream& operator<<(std::ostream& stream, Location& location);
    std::string get_name() const { return name; };
private:
    int trafficCoefficient;
    double latitude, longitude;
    std::string name;
};

#endif