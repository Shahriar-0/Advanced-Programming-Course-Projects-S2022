#ifndef __IO_HANDLER_HPP__
#define __IO_HANDLER_HPP__

#include <iostream>
#include <cstring>
#include <fstream>
#include "../requests/get_request.hpp"
#include "../requests/delete_request.hpp"
#include "../requests/post_request.hpp"
#include "../datas/database.hpp"

enum RequestType { GET, POST, DELETE };
const std::string RequestTypeString[] { "GET", "POST", "DELETE" };

class IOHandler {
public:
    IOHandler(std::string filename);
    void read_locations(DataBase& database);
    Request* generate_request(std::string line);
private:
    std::string filename;
};

#endif