#include "Library.hh"

Document* Library::search_document(std::string title) const {
    for (auto& document : documents)
        if (*document == title)
            return document;
    return nullptr;
}

Person* Library::search_people(std::string name) const {
    for (auto& person : people) 
        if (*person == name)
            return person;
    return nullptr;    
}

void Library::check_for_repetition_in_document(std::string title) const {
    Document* document = search_document(title);
    if (document != nullptr)
        errorHandler->show_error(REPEATED_TITLE);
} 

void Library::check_for_repetition_in_people(std::string name) const {
    Person* person = search_people(name);
    if (person != nullptr)
        errorHandler->show_error(ALREADY_A_MEMBER);
}

void Library::add_student_member(std::string id, std::string name) {
    check_for_repetition_in_people(name);
    people.push_back(new Student(name, id));
}

void Library::add_prof_member(std::string name) {
    check_for_repetition_in_people(name);
    people.push_back(new Professor(name));
}

void Library::add_book(std::string title, int copies) {
    check_for_repetition_in_document(title);
    while (copies--)
        documents.push_back(new Book(title));
}

void Library::add_reference(std::string title, int copies) {
    check_for_repetition_in_document(title);
    while (copies--)
        documents.push_back(new Reference(title));
}

void Library::add_magazine(std::string title, int year, int number, int copies) {
    check_for_repetition_in_document(title);
    while (copies--)
        documents.push_back(new Magazine(title, year, number));
}

void Library::borrow(std::string name, std::string title) {
    Document* document = search_document(title);
    Person* person = search_people(name);
    if (document == nullptr)
        errorHandler->show_error(DOES_NOT_EXIST_DOCUMENT);
    
    if (person->can_borrow(title))
        person->borrow_document(document);
}

void Library::extend(std::string name, std::string title) {
    search_people(name)->extend(title);
}

void Library::return_document(std::string name, std::string title) {
    search_people(name)->return_document(title);
}

int Library::get_total_penalty(std::string name) {
    return search_people(name)->calculate_penalty();
}

void Library::time_pass(int days) {
    for (auto& person : people)
        person->time_pass(days);
}

std::vector<std::string> Library::available_titles() {
    std::vector<std::string> result;
    for (auto& document : documents) {
        if (((result.size() > 0 && !(*document == result[result.size() - 1])) || result.size() == 0) && document->is_available())
            result.push_back(document->get_name());
    }
    return result;
}