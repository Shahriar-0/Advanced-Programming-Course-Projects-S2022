#ifndef __UTAXI_HPP__
#define __UTAXI_HPP__

#include "database.hpp"
#include "driver.hpp"
#include "passenger.hpp"
#include "delete_request.hpp"
#include "get_request.hpp"
#include "post_request.hpp"
#include "IO_handler.hpp"
#include "error_handler.hpp"

class UTaxi {
public:
    UTaxi(std::string filename);
    void run();
private:
    DataBase database;
    IOHandler IOHandlerVar;
    Request* request;
};

#endif