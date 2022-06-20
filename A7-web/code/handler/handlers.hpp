#ifndef _MY_HANDLERS_
#define _MY_HANDLERS_

#include "../server/server.hpp"
#include "../manager/utaxi.hpp"
#include <iostream>

class SignupHandler : public RequestHandler {
public:
    SignupHandler(UTaxi* _manager) { manager = _manager; };
    Response* callback(Request* request) override;
private:
    UTaxi* manager;
};

class ShowTripHandler : public RequestHandler {
public:
    ShowTripHandler(UTaxi* _manager) { manager = _manager; };
    Response* callback(Request* request) override;
private:
    UTaxi* manager;
};

class DeleteTripHandler : public RequestHandler {
public:
    DeleteTripHandler(UTaxi* _manager) { manager = _manager; };
    Response* callback(Request* request) override;
private:
    UTaxi* manager;
};

class SubmitTripHandler : public RequestHandler {
public:
    SubmitTripHandler(UTaxi* _manager) { manager = _manager; };
    Response* callback(Request* request) override;
private:
    UTaxi* manager;
};

class AcceptTripHandler : public RequestHandler {
public:
    AcceptTripHandler(UTaxi* _manager) { manager = _manager; };
    Response* callback(Request* request) override;
private:
    UTaxi* manager;
};

class FinishTripHandler : public RequestHandler {
public:
    FinishTripHandler(UTaxi* _manager) { manager = _manager; };
    Response* callback(Request* request) override;
private:
    UTaxi* manager;
};
#endif
