/**
 *  @file   Person.hpp
 *  @brief  BOM representing a Person
 */
#ifndef PERSON_HPP
#define PERSON_HPP
#include <string>
#include <locale>
#include <algorithm>

struct Person{
    std::string Name;
    std::string PhoneNbr;
    std::string Answers;
    std::string Names;
    bool hasValidPhoneNumber(std::string number);
    bool hasValidName(std::string name);
};

#endif /*< PERSON_HPP */