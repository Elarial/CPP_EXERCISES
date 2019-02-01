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
    bool hasValidPhoneNumber();
    bool hasValidNames();
    int getNumberOfPositiveResponses();
    int getNumberOfGivenResponses();
};
bool stringIsAlpha(std::string s);

#endif /*< PERSON_HPP */