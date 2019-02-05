/**
 *  @file   Fraction.hpp
 *  @brief  struct representing a fraction.
 */
#ifndef FRACTION_HPP
#define FACTION_HPP

#include <string>
#include <iostream>

struct Fraction
{
    int numerator;
    int denominator;
    //Print Fraction content.
    std::string display();
    //Constructor
    Fraction(int num=1,int den=1);
    //Operator oveload using same denominator algorith
    Fraction operator+ (int i);
    //Operator oveload using same denominator algorith
    Fraction operator+ (const Fraction a);    
    //Operator oveload using same denominator algorith
    bool operator> (const Fraction a);
    //Operator oveload using same denominator algorith
    bool operator< (const Fraction a);
    
    bool operator== (const Fraction a);
    /* Calculates the greates common divisor with 
    Euclid's algorithm
    both arguments have to be positive*/
    int gcd (int a,int b);
};
//Function allowing to parse a string into Fraction. Have to be static so is declared outside of struct.
Fraction strToFrac (const std::string str);

#endif /*< FRACTION_HPP */