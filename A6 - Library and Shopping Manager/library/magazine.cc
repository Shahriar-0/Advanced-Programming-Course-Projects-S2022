#include "magazine.hh"

Magazine::Magazine(std::string _title, int _year, int _number) : Document(_title), year(_year), number(_number) {
    if (_year <= 0)
        errorHandler->show_error(INVALID_YEAR);
    if (_number < 0)
        errorHandler->show_error(INVALID_NUMBER);
};

void Magazine::extend() {
    if (can_be_extended()) {
        //we never get here cause the can_be_extended function will return false
    }
}

bool Magazine::can_be_extended() const {
    errorHandler->show_error(RENEWING_A_MAGAZINE);
    return false;   //for now it's not renewable
}

int Magazine::calculate_penalty() const {
    int dayLate = dayPassed - maxDay;   
    int penalty = 0;
    
    if (dayLate < 0)
        return penalty;

    if (year < CHANGING_PRICE_YEAR)
        penalty = dayLate * BEFORE_1390_PENALTY;
    else 
        penalty = dayLate * AFTER_1390_PENALTY;
    
    return penalty;
}

void Magazine::is_getting_borrowed() {
    dayPassed = 0;
    maxDay = MAGAZINE_RETURN_TIME_PERIOD;
}