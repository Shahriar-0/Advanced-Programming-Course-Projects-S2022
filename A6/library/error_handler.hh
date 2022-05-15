#ifndef __ERROR_HANDLER_HH__
#define __ERROR_HANDLER_HH__
#include <string>
#include <iostream>
#include <cstdlib>

enum ErrorType {
    ALREADY_A_MEMBER,
    EMPTY_FIELD,
    REPEATED_TITLE,
    INVALID_NUMBER,
    INVALID_YEAR,
    EXTENDING_ON_FIRST_DAY,
    EXTENDING_AFTER_RECEIVING_PENALTY,
    EXCEEDED_MAX_RENEW,
    EXCEEDED_MAX_BORROW,
    RENEWING_A_MAGAZINE,
    WORK_WITH_A_NOT_BORROWED_DOCUMENT,
    ALREADY_BORROWED,
    DOES_NOT_EXIST_DOCUMENT 
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