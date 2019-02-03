#include <iostream>

#include <test/catch.hpp>

#include "subdir/Person.hpp"




/* ########################################################################## */
TEST_CASE("Test de l'objet Personne","Person"){
    Person person;
    person.PhoneNbr="0636757575";
    REQUIRE(person.hasValidPhoneNumber()==true);

    person.PhoneNbr="1636757575";
    REQUIRE_FALSE(person.hasValidPhoneNumber()==true);

    person.PhoneNbr="636757575";
    REQUIRE_FALSE(person.hasValidPhoneNumber()==true);

    person.FirstName = "Adrien";
    person.LastName = "Cianci";
    REQUIRE(person.hasValidNames()==true);

    person.LastName = "1drien";
    REQUIRE_FALSE(person.hasValidNames()==true);

    person.LastName = "";
    REQUIRE_FALSE(person.hasValidNames()==true);

    person.Answer= Fraction(3,4);
    REQUIRE(person.getNumberOfGivenResponses() == 4);
    REQUIRE(person.getNumberOfPositiveResponses() == 3);
}

/* ########################################################################## */
