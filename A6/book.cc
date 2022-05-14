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
        errorHandler->show_error(EXCEEDED_MAX_RENEW);
    //there's an exit in show error function so if we pass that point it's allright
    return Document::can_be_extended();
}

int Book::calculate_penalty() const {
    int dayLate = dayPassed - maxDay;   
    int penalty;

    if (dayLate < 0)
        penalty = 0;
    else if (dayLate <= FIRST_PENALTY_PERIOD_BOOK)
        penalty = dayLate * FIRST_PENALTY_BOOK;
    else if (dayLate <= SECOND_PENALTY_PERIOD)
        penalty = FIRST_PENALTY_PERIOD_BOOK * FIRST_PENALTY_BOOK + 
          (dayLate - FIRST_PENALTY_PERIOD_BOOK) * SECOND_PENALTY_BOOK;
    else 
        penalty = FIRST_PENALTY_PERIOD_BOOK * FIRST_PENALTY_BOOK +
          (SECOND_PENALTY_PERIOD - FIRST_PENALTY_PERIOD_BOOK) * SECOND_PENALTY_BOOK +
          (dayLate - SECOND_PENALTY_PERIOD) * THIRD_PENALTY;
    
    return penalty;
}

void Book::is_getting_borrowed() {
    dayPassed = 0;
    maxDay = BOOK_RETURN_TIME_PERIOD;
}