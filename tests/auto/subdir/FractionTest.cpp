#include <test/catch.hpp>

#include "subdir/Fraction.hpp"

/* ########################################################################## */
TEST_CASE("Test de l'objet fraction","[Frac]"){
    Fraction fraction;
    REQUIRE(fraction.display()=="1/1");

    Fraction fraction2(20,50);
    REQUIRE(fraction2.display()=="20/50");

    Fraction sumFrac = fraction+fraction2;
    REQUIRE(sumFrac.numerator==70);
    REQUIRE(sumFrac.denominator==50);
    
    Fraction sumInt = fraction2 + 2;
    REQUIRE(sumInt.numerator==6000);
    REQUIRE(sumInt.denominator==2500);

    REQUIRE((fraction > fraction2)==true);
    REQUIRE((fraction < fraction2)==false);
    Fraction fraction3(2,5);
    REQUIRE((fraction2==fraction3)==true);

    std::string str = "3/2";
    Fraction fraction4(3,2);
    fraction3 = strToFrac(str);
    REQUIRE((fraction3==fraction4)==true);
}
/* ########################################################################## */