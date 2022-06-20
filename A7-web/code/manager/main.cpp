#include "../handler/handlers.hpp"

int main(int argc, char* argv[]) {
    UTaxi manager(argv[1]);
    try {
        Server server(5000);
        server.get("/", new ShowPage("static/home.html"));
        server.get("/home.css", new ShowPage("static/home.css"));
        server.get("/background.jpg", new ShowImage("static/background.jpg"));
        server.get("/signup", new ShowPage("static/signup.html"));
        server.get("/ask-for-trip", new ShowPage("static/ask-for-trip.html"));
        server.get("/delete-trip", new ShowPage("static/delete-trip.html"));
        server.get("/show-trips", new ShowPage("static/show-trips.html"));
        server.get("/ok", new ShowPage("static/ok.html"));
        server.get("/bad-request", new ShowPage("static/bad-request.html"));
        server.get("/permission-denied", new ShowPage("static/permission-denied.html"));
        server.get("/not-found", new ShowPage("static/not-found.html"));
        server.run();
    }
    catch (Server::Exception& e) {
        std::cerr << e.what() << std::endl;
    }
}