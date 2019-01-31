/**
 *  @file  Fraction.cpp
 *  @brief Source file of the fraction object.
 */

#include "Fraction.hpp"
/* ########################################################################## */

std::string Fraction::display (){
    std::string s = std::to_string(this->numerator)+"/"+std::to_string(this->denominator);
    return s;
}

/* Calculates the greates common divisor with 
Euclid's algorithm
both arguments have to be positive*/

int Fraction::gcd(int a, int b)
{
    while (a != b){
        if (a > b){
            a -= b;
        }
        else{
            b -= a;
        }
    }
    return a;
}
Fraction::Fraction(int num,int den){
    if (den == 0)
    {
        std::cerr << "Denominator may not be 0." << std::endl;
        exit(EXIT_FAILURE);
    }
    else if (num == 0)
    {
        this->numerator = 0;
        this->denominator = 1;
    }
    else
    {
        int sign = 1;
        if (num < 0)
        {
            sign *= -1;
            num *= -1;
        }
        if (den < 0)
        {
            sign *= -1;
            den *= -1;
        }

        int tmp = gcd(num, den);
        this->numerator = num / tmp * sign;
        this->denominator = den / tmp;
    }
}
Fraction Fraction::operator+(const Fraction a) {
    Fraction fraction(this->numerator*a.denominator+this->denominator*a.numerator,this->denominator * a.denominator);
    return fraction;
                      
}

Fraction Fraction::operator+(int i) {
   //Mistake here
    Fraction iFrac(i,i);
    Fraction fraction = *this + iFrac;
    return fraction;
}

/* ########################################################################## */