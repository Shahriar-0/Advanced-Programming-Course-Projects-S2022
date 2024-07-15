#include "location.hpp"

Location::Location(std::string _name, int _latitude, int _longitude)
        : name(_name), latitude(_latitude), longitude(_longitude) {}

void operator>>(std::string& line, Location& location) {
    size_t index = line.find(FILE_DELIMITER);
    if (index == std::string::npos)
        throw ErrorHandler(BAD_REQUEST, "invalid input file");
    location.name = line.substr(0, index);
    line = line.substr(index + 1);

    index = line.find(FILE_DELIMITER);
    if (index == std::string::npos)
        throw ErrorHandler(BAD_REQUEST, "invalid input file");
    location.latitude = stod(line.substr(0, index));
    line = line.substr(index + 1);

    location.longitude = stod(line);
}

std::ostream& operator<<(std::ostream& out, Location& location) {
    out << location.name;
    return out;
}

bool Location::operator==(std::string _name) const {  return name == _name; }