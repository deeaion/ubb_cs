//
// Created by Deea on 5/23/2023.
//

#ifndef PARTIAL_IONANDREEA_EXCEPTIONS_H
#define PARTIAL_IONANDREEA_EXCEPTIONS_H
#include <iostream>
#include <exception>
using namespace std;
class ValidException : public exception{
    string message;
public:
    ValidException(const string & m):message(m){};
    const string &get_message(){return message;};
};


#endif //PARTIAL_IONANDREEA_EXCEPTIONS_H
