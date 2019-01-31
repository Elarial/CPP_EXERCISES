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
    std::string display();
    Fraction(int num=1,int den=1);
    Fraction operator+ (int i);
    Fraction operator+ (const Fraction a);
    int gcd (int a,int b);
};


#endif /*< FRACTION_HPP */