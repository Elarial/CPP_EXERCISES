/**
 *  @file   Person.cpp
 *  @brief  BOM representing a person
 */
#include "Person.hpp"




/* ########################################################################## */
//Function check if number begin with 0, has 10 chars and is only digits chars
bool Person::hasValidPhoneNumber(){
    if(this->PhoneNbr[0]=='0' 
    && this->PhoneNbr.size()==10 
    && std::count_if(this->PhoneNbr.begin(),this->PhoneNbr.end(),isdigit)==(int)this->PhoneNbr.size())
        return true;
    return false;
}
//Function check if both Last and First names are alpha and not empty
bool Person::hasValidNames(){
    if(stringIsAlpha(this->LastName) && stringIsAlpha(this->FirstName))
        return true;
    return false;
}
//Function check if the string is not empty and is only alpha
bool stringIsAlpha(std::string s){
    if (s.size()!=0 && std::count_if(s.begin(),s.end(),isalpha)==(int)s.size()){
        return true;
    }
    return false;
}

int Person::getNumberOfPositiveResponses(){
    return this->Answer.numerator;
}
int Person::getNumberOfGivenResponses(){
    return this->Answer.denominator;
}
/* ########################################################################## */
