#include "location.hpp"

Location::Location(std::string _name, int _latitude, int _longitude)
        : name(_name), latitude(_latitude), longitude(_longitude) {}

void operator>>(std::string& line, Location& location) {
    size_t index = line.find(FILE_DELIMITER);
    location.name = line.substr(0, index);
    line = line.substr(index + 1);

    index = line.find(FILE_DELIMITER);
    location.latitude = stod(line.substr(0, index));
    line = line.substr(index + 1);

    index = line.find(FILE_DELIMITER);
    location.longitude = stod(line.substr(0, index));
    line = line.substr(index + 1);

    location.trafficCoefficient = stoi(line);
}


std::ostream& operator<<(std::ostream& out, Location& location) {
    out << location.name;
    return out;
}

double Location::operator-(const Location& other) const {
    return EUCLIDEAN_CONVERTER * (sqrt(pow(latitude - other.latitude, 2) + pow(longitude - other.longitude, 2)));
}

int Location::get_traffic_coefficient() const { return trafficCoefficient; }
bool Location::operator==(std::string _name) const {  return name == _name; }