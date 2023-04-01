//
// Created by Deea on 4/1/2023.
//

#ifndef LAB_6_7_EXCEPTIONS_H
#define LAB_6_7_EXCEPTIONS_H
//includes
#include <exception>
#include <string>
#include <utility>

using std::string;

class RepositoryException : public std::exception {
    string message;

public:
    explicit RepositoryException(string message) : message{std::move(message)} {};

    string getMessage() { return this->message; };

};

class ValidatorException : public std::exception {
    std::string message;
public:
    explicit ValidatorException(string message) : message(std::move(message)) {};

    std::string getMessage() { return this->message; };
};


#endif //LAB_6_7_EXCEPTIONS_H
