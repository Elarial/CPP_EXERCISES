/**
 *  @file   Person.cpp
 *  @brief  BOM representing a person
 */
#include "Person.hpp"




/* ########################################################################## */
bool Person::hasValidPhoneNumber(std::string number){
    if(number[0]=='0' && number.size()==10 && std::count_if(number.begin(),number.end(),isdigit)==(int)number.size())
        return true;
    return false;
}
bool Person::hasValidName(std::string name){
    if (name.size()!=0 && std::count_if(name.begin(),name.end(),isalpha)==(int)name.size()){
        return true;
    }
    return false;
}
/* ########################################################################## */
