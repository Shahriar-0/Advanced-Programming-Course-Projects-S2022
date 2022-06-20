#include "handlers.hpp"

Response* SignupHandler::callback(Request* request) {
    Response* response = new Response;
    response->setHeader("Content-Type", "text/html");
    std::string username = request->getBodyParam("username");
    std::string role = request->getBodyParam("role");
    std::string line = "POST signup ? username " + username + " role " + role;
    try {
        manager->run(line, username, response);
        return Response::redirect("/ok");
    }
    catch(ErrorHandler& error) {
        response->setBody(error.get_page());
        return response;
    }
}

Response* ShowTripHandler::callback(Request* request) {
    Response* response = new Response;
    response->setHeader("Content-Type", "text/html");
    std::string username = request->getBodyParam("username");
    std::string sort = request->getBodyParam("sort_by_cost");
    std::string line = "GET trips ? username " + username + " sort_by_cost " + sort;
    try {
        manager->run(line, username, response);
        return response;
    }
    catch(ErrorHandler& error) {
        response->setBody(error.get_page());
        return response;
    }
}

Response* DeleteTripHandler::callback(Request* request) {
    Response* response = new Response;
    response->setHeader("Content-Type", "text/html");
    std::string username = request->getBodyParam("username");
    std::string id = request->getBodyParam("id");
    std::string line = "DELETE trips ? username " + username + " id " + id;
    try {
        manager->run(line, username, response);
        return Response::redirect("/ok");
    }
    catch(ErrorHandler& error) {
        response->setBody(error.get_page());
        return response;
    }
}


Response* SubmitTripHandler::callback(Request* request) {
    Response* response = new Response;
    response->setHeader("Content-Type", "text/html");
    std::string username = request->getQueryParam("username");
    std::string origin = request->getQueryParam("origin");
    std::string destination = request->getQueryParam("destination");
    std::string hurry = request->getQueryParam("hurry");
    std::string line = "POST trips ? username " + username + " origin " + origin + " destination " + destination + " in_hurry " + hurry;
    try {
        manager->run(line, username, response);
        return response;
    }
    catch(ErrorHandler& error) {
        response->setBody(error.get_page());
        return response;
    }
}

Response* GetCostHandler::callback(Request* request) {
    Response* response = new Response;
    response->setHeader("Content-Type", "text/html");
    std::string username = request->getQueryParam("username");
    std::string origin = request->getQueryParam("origin");
    std::string destination = request->getQueryParam("destination");
    std::string hurry = request->getQueryParam("hurry");
    std::string line = "GET cost ? username " + username + " origin " + origin + " destination " + destination + " in_hurry " + hurry;
    try {
        manager->run(line, username, response);
        return response;
    }
    catch(ErrorHandler& error) {
        response->setBody(error.get_page());
        return response;
    }
}

Response* AcceptTripHandler::callback(Request* request) {
    Response* response = new Response;
    response->setHeader("Content-Type", "text/html");
    std::string username = request->getQueryParam("username");
    std::string id = request->getQueryParam("id");
    std::string line = "POST accept ? username " + username + " id " + id;
    try {
        manager->run(line, username, response);
        return Response::redirect("/ok");
    }
    catch(ErrorHandler& error) {
        response->setBody(error.get_page());
        return response;
    }
}


Response* FinishTripHandler::callback(Request* request) {
    Response* response = new Response;
    response->setHeader("Content-Type", "text/html");
    std::string username = request->getQueryParam("username");
    std::string id = request->getQueryParam("id");
    std::string line = "POST finish ? username " + username + " id " + id;
    try {
        manager->run(line, username, response);
        return Response::redirect("/ok");
    }
    catch(ErrorHandler& error) {
        response->setBody(error.get_page());
        return response;
    }
}

