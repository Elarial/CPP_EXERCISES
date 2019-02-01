#include <test/catch.hpp>

#include "subdir/Fraction.hpp"

/* ########################################################################## */
TEST_CASE("Test de l'objet fraction","[Frac]"){
    Fraction fraction;
    REQUIRE(fraction.display()=="1/1");

    Fraction fraction2(20,50);
    REQUIRE(fraction2.display()=="2/5");

    Fraction sumFrac = fraction+fraction2;
    REQUIRE(sumFrac.numerator==7);
    REQUIRE(sumFrac.denominator==5);
    
    Fraction sumInt = fraction2 + 2;
    REQUIRE(sumInt.numerator==12);
    REQUIRE(sumInt.denominator==5);

    REQUIRE((fraction > fraction2)==true);
    REQUIRE((fraction < fraction2)==false);
    Fraction fraction3(2,5);
    REQUIRE((fraction2==fraction3)==true);
}
/* ########################################################################## */