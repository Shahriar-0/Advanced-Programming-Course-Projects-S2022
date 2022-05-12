#include "book.hh"

Book::Book(std::string _title) : Document(_title) {};

void Book::extend() {
    if (can_be_extended()) {
        maxDay += BOOK_RETURN_TIME_PERIOD;
        numOfExtension++;
    }
}

bool Book::can_be_extended() const {
    if (numOfExtension == BOOK_MAX_EXTENSION)
        errorHandler->show_error(EXCEEDED_MAX_BORROW);
    //there's an exit in show error function so if we pass that point it's allright
    return Document::can_be_extended();
}

int Book::calculate_penalty() const {
    int dayLate = dayPassed - maxDay;   
    int penalty = 0;

    if (dayLate <= FIRST_PENALTY_PERIOD)
        penalty = dayLate * FIRST_PENALTY;
    else if (dayLate <= SECOND_PENALTY_PERIOD)
        penalty = FIRST_PENALTY_PERIOD * FIRST_PENALTY + 
          (dayLate - FIRST_PENALTY_PERIOD) * SECOND_PENALTY;
    else 
        penalty = FIRST_PENALTY_PERIOD * FIRST_PENALTY +
          (SECOND_PENALTY_PERIOD - FIRST_PENALTY_PERIOD) * SECOND_PENALTY +
          (dayLate - SECOND_PENALTY_PERIOD) * THIRD_PENALTY;
    
    return penalty;
}