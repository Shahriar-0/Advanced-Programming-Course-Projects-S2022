#ifndef __PERSON_HH__
#define __PERSON_HH__
#include <vector>
#include "error_handler.hh"
#include "document.hh"

class Person {
public:
    virtual bool can_borrow() const = 0;
    virtual int calculate_penalty() const = 0;
    void borrow_document(Document*);
    void return_document(std::string);
    void extend(std::string);
protected:
    Document* find_document(std::string);
    int returnDocumentsPenalty;
    std::vector<Document*> documents;
};

#endif