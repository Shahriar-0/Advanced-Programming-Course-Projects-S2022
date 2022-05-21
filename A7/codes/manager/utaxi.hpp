#ifndef __UTAXI_HPP__
#define __UTAXI_HPP__

#include "../data/database/database.hpp"
#include "../data/people/person.hpp"
#include "../data/people/passenger.hpp"
#include "../data/people/driver.hpp"
#include "../request/delete_request.hpp"
#include "../request/get_request.hpp"
#include "../request/post_request.hpp"
#include "../IO/IO_handler.hpp"
#include "../error/error_handler.hpp"

class UTaxi {
public:
    UTaxi(std::string filename);
    void run();
private:
    DataBase database;
    IOHandler IOHandler;
    Request* request;
};

#endif