#ifndef __PERSON_HH__
#define __PERSON_HH__
#include <vector>
#include "error_handler.hh"
#include "document.hh"

class Person {
public:
    Person(std::string);
    virtual int calculate_penalty() const;
    void return_document(std::string);
    void extend(std::string);
    void time_pass(int);

    virtual bool can_borrow() const = 0;
    virtual void borrow_document(Document*) = 0;
protected:
    int find_document_index(std::string);
    int returnDocumentsPenalty;
    std::vector<Document*> documents;
    std::string name;
    ErrorHandler* errorHandler;
};

#endif