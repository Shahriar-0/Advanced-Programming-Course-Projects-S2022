#include "location.hpp"

Location::Location(std::string _name, int _latitude, int _longitude)
        : name(_name), latitude(_latitude), longitude(_longitude) {}

std::ifstream& operator>>(std::ifstream& inputStream, Location& location) {
    char comma = ',';
    std::string line;
    inputStream >> line;
    
    int index = line.find(comma);
    if (index == std::string::npos)
        throw ErrorHandler(BAD_REQUEST, "invalid input file");
    location.name = line.substr(0, index);
    line = line.substr(index);

    index = line.find(comma);
    if (index == std::string::npos)
        throw ErrorHandler(BAD_REQUEST, "invalid input file");
    location.latitude = stoi(line.substr(0, index));
    line = line.substr(index);

    location.longitude = stoi(line);

    return inputStream;
}

bool Location::operator==(std::string _name) const {  return name == _name; }