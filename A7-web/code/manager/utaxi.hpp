#ifndef __UTAXI_HPP__
#define __UTAXI_HPP__

#include "../datas/database.hpp"
#include "../datas/driver.hpp"
#include "../datas/passenger.hpp"
#include "../requests/delete_request.hpp"
#include "../requests/get_request.hpp"
#include "../requests/post_request.hpp"
#include "../IO/IO_handler.hpp"
#include "../error/error_handler.hpp"

class UTaxi {
public:
    UTaxi(std::string filename);
    void run();
private:
    DataBase database;
    IOHandler IOHandlerVar;
    SystemRequest* request;
};

#endif