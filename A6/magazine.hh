#ifndef __MAGAZINE_HH__
#define __MAGAZINE_HH__
#include "document.hh"

constexpr int BEFORE_1390_PENALTY = 2000;
constexpr int AFTER_1390_PENALTY  = 3000;
constexpr int CHANGING_PRICE_YEAR = 1390;

class Magazine : public Document {
public:
    Magazine(std::string, int, int);
    virtual void extend();
    virtual int calculate_penalty() const;
protected:
    virtual bool can_be_extended() const;
private:
    int year;
    int number;
};

#endif