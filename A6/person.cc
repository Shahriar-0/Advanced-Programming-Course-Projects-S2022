#include "person.hh"

Person::Person(std::string _name) : name(_name) {
    if (_name == EMPTY_STRING)
        errorHandler->show_error(EMPTY_FIELD);
}

void Person::time_pass(int days) {
    for (auto& document : documents)
        document->time_pass(days);
}

int Person::calculate_penalty() const {
    int totalPenalty = returnDocumentsPenalty;
    for (auto& document : documents)
        totalPenalty += document->calculate_penalty();
    return totalPenalty;
}

int Person::find_document_index(std::string title) {
    for (int i = 0; i < documents.size(); i++) 
        if (*(documents[i]) == title) 
            return i;
    return NOT_FOUND_INDEX;
}

void Person::return_document(std::string title) {
    int index = find_document_index(title);
    if (index == NOT_FOUND_INDEX)
        errorHandler->show_error(WORK_WITH_A_NOT_BORROWED_DOCUMENT);
    documents[index]->initialise();
    documents.erase(documents.begin() + index);
}

void Person::extend(std::string title) {
    int index = find_document_index(title);
    if (index == NOT_FOUND_INDEX)
        errorHandler->show_error(WORK_WITH_A_NOT_BORROWED_DOCUMENT);
    documents[index]->extend();
}

bool Person::can_borrow(std::string title) {
    if (find_document_index(title) != NOT_FOUND_INDEX)
        errorHandler->show_error(ALREADY_BORROWED);
    return true;
}

void Person::borrow_document(Document* document) { documents.push_back(document); }