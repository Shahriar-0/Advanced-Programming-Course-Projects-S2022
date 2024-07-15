#include "../handler/handlers.hpp"

int main(int argc, char* argv[]) {
    UTaxi manager(argv[1]);
    try {
        Server server(5000);
        server.get("/", new ShowPage("static/home.html"));
        server.get("/home.css", new ShowPage("static/home.css"));
        server.get("/background.jpg", new ShowImage("static/background.jpg"));
        server.get("/signup", new ShowPage("static/signup.html"));
        server.post("/signup", new SignupHandler(&manager));
        // server.get("/ask-for-trip", new ShowPage("static/ask-for-trip.html"));
        server.get("/ask-for-trip", new AskTripFormHandler(&manager));
        server.get("/submit-trip", new SubmitTripHandler(&manager));
        server.get("/get-cost", new GetCostHandler(&manager));
        server.get("/delete-trip", new ShowPage("static/delete-trip.html"));
        server.post("/delete-trip", new DeleteTripHandler(&manager));
        server.get("/show-trips", new ShowPage("static/show-trips.html"));
        server.post("/show-trips", new ShowTripHandler(&manager));
        server.get("/accept-trip", new AcceptTripHandler(&manager));
        server.get("/finish-trip", new FinishTripHandler(&manager));
        server.get("/ok", new ShowPage("static/ok.html"));
        server.run();
    }
    catch (Server::Exception& e) {
        std::cerr << e.what() << std::endl;
    }
}