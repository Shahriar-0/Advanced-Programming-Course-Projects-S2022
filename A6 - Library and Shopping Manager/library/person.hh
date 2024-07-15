#ifndef __PERSON_HH__
#define __PERSON_HH__
#include <vector>
#include "error_handler.hh"
#include "document.hh"

constexpr int NOT_FOUND_INDEX = -1;

class Person {
public:
    Person(std::string);
    void return_document(std::string);
    void extend(std::string);
    void time_pass(int);
    void borrow_document(Document*);
    int calculate_penalty() const;
    bool operator ==(std::string);
    virtual bool can_borrow(std::string);
protected:
    int find_document_index(std::string);
    int returnDocumentsPenalty;
    std::vector<Document*> documents;
    std::string name;
    ErrorHandler* errorHandler;
};

#endif