#include "passenger.hpp"

Passenger::Passenger(std::string _username) : Person(_username) {}

void Passenger::has_asked_for_trip() {
    state = IS_WAITING;
}

void Passenger::can_ask_for_trip() {
    if (state == IS_TRAVELING)
        throw ErrorHandler("Bad Request", "can't be in two trips simultaneously");
}

void Passenger::can_accept_a_trip() {
    throw ErrorHandler("Permission Denied", "passengers can't accept a trip");
}