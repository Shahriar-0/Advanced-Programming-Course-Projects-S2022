#ifndef __DOCUMENT_HH__
#define __DOCUMENT_HH__
#include "error_handler.hh"

#define EMPTY_STRING ""

class Document {
public:
    Document(std::string);
    void initialise();
    bool operator ==(std::string) const;
    virtual void extend() = 0;
    virtual int calculate_penalty() const = 0;
protected:
    virtual bool can_be_extended() const = 0;
    bool isBorrowed;
    std::string title;
    int numOfExtension;
    int dayPassed, maxDay;
    ErrorHandler* errorHandler;
};

#endif