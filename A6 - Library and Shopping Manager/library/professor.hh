#ifndef __PROFESSOR_HH__
#define __PROFESSOR_HH__
#include "person.hh"

constexpr int MAX_PROFESSOR_BORROW = 5;

class Professor : public Person {
public:
    Professor(std::string);
    virtual bool can_borrow(std::string);
};

#endif