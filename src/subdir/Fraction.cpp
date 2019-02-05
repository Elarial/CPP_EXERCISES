/**
 *  @file  Fraction.cpp
 *  @brief Source file of the fraction object.
 */

#include "Fraction.hpp"
/* ########################################################################## */
std::string Fraction::display()
{
    std::string s = std::to_string(this->numerator) + "/" + std::to_string(this->denominator);
    return s;
}

/* Calculates the greates common divisor with 
Euclid's algorithm
both arguments have to be positive*/

int Fraction::gcd(int a, int b)
{
    while (a != b)
    {
        if (a > b)
        {
            a -= b;
        }
        else
        {
            b -= a;
        }
    }
    return a;
}
Fraction::Fraction(int num, int den)
{
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

        //Could have use gcd algorithm  for maths fraction.
        //Inapropiate for survey fraction.
        //uncomment line below to use gcd.

        // int tmp = gcd(num, den);
        // this->numerator = num / tmp * sign;
        // this->denominator = den / tmp;
        this->numerator = num * sign;
        this->denominator = den;
    }
}
//Operator oveload using same denominator algorithm
Fraction Fraction::operator+(const Fraction a)
{
    Fraction fraction(this->numerator * a.denominator + this->denominator * a.numerator, this->denominator * a.denominator);
    return fraction;
}
//Operator oveload using same denominator algorithm
Fraction Fraction::operator+(int i)
{
    Fraction iFrac(i * this->denominator, this->denominator);
    Fraction fraction = *this + iFrac;
    return fraction;
}
//Operator oveload using same denominator algorithm
bool Fraction::operator>(const Fraction a)
{
    if (this->numerator * a.denominator > this->denominator * a.numerator)
        return true;
    return false;
}
//Operator oveload using same denominator algorithm
bool Fraction::operator<(const Fraction a)
{
    if (this->numerator * a.denominator < this->denominator * a.numerator)
        return true;
    return false;
}
//If fraction is not < and not > then it's ==
bool Fraction::operator==(const Fraction a)
{
    if (!(*this > a) && !(*this < a))
        return true;
    return false;
}
//Function allowing to parse a string into Fraction
Fraction strToFrac(const std::string str)
{
    //Find the slash character as separator
    std::size_t pos = str.find('/');
    //Try to parse numerator and denominator, returning a fraction.
    try
    {
        Fraction frac(std::stoi(str.substr(0, pos)), std::stoi(str.substr(pos + 1)));
        return frac;
    }
    //Catch and log the error
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}
/* ########################################################################## */