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
    
    Fraction sumInt = fraction2 + 7;
    CHECK(sumInt.numerator==36);
    REQUIRE(sumInt.denominator==5);
}
/* ########################################################################## */