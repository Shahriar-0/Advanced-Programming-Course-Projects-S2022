#ifndef __ERROR_HANDLER_HH__
#define __ERROR_HANDLER_HH__
#include <string>

enum ErrorType {
    ALREADY_MEMBER_NAME,
    EMPTY_FIELD_ERROR,
    REPEATED_TITLE_ERROR,
    INVALID_NUMBER_ERROR,
    INVALID_YEAR_ERROR,
    EXTEND_IN_FIRST_DAY_ERROR,
    EXTEND_AFTER_PENALTY_ERROR,
    EXCEED_MAX_RENEW,
    EXCEED_MAX_BORROW,
    RENEW_MAGAZINE_ERROR,
    EXTEND_NOT_BORROWED_DOCUMENT,
    BORROW_NOT_AVAILABLE_DOCUMENT,
    NOT_EXIST_DOCUMENT 
};

const std::string errorMassages[] {
    "Name already exists",
    "Empty field",
    "A document with the specified name already exists",
    "Invalid number",
    "Invalid year",
    "You can’t extend and borrow a document on the same day",
    "You can’t renew a document after receiving a penalty",
    "You can’t renew a document more than two times",
    "Maximum number of allowed borrows exceeded",
    "You can’t renew magazines",
    "You have not borrowed this document",
    "You borrowed this document already",
    "This document does not exist"
};


class ErrorHandler {
public:
    void show_error(ErrorType);
};

#endif