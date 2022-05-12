#ifndef __BOOK_HH__
#define __BOOK_HH__
#include "document.hh"

constexpr int BOOK_RETURN_TIME_PERIOD = 10;
constexpr int BOOK_MAX_EXTENSION      = 2;
constexpr int FIRST_PENALTY_PERIOD    = 7;
constexpr int FIRST_PENALTY           = 2000;
constexpr int SECOND_PENALTY_PERIOD   = 21;
constexpr int SECOND_PENALTY          = 3000;
constexpr int THIRD_PENALTY           = 5000;


class Book : public Document {
public:
    Book(std::string);
    virtual void extend();
    virtual int calculate_penalty() const;
protected:
    virtual bool can_be_extended() const;
};

#endif