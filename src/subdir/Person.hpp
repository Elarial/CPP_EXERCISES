/**
 *  @file   Person.hpp
 *  @brief  BOM representing a Person
 */
#ifndef PERSON_HPP
#define PERSON_HPP
#include <string>
#include <locale>
#include <algorithm>
#include "Fraction.hpp"

struct Person{
    std::string FirstName;
    std::string LastName;
    std::string PhoneNbr;
    Fraction Answer;
    //Function check if number begin with 0, has 10 chars and is only digits chars
    bool hasValidPhoneNumber();
    //Function check if both Last and First names are alpha and not empty
    bool hasValidNames();
    int getNumberOfPositiveResponses();
    int getNumberOfGivenResponses();
};
//Function check if the string is not empty and is only alpha
bool stringIsAlpha(std::string s);

#endif /*< PERSON_HPP */