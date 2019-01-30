#include <iostream>

#include <test/catch.hpp>

#include "subdir/Person.hpp"




/* ########################################################################## */
TEST_CASE("Test de l'objet Personne","Person"){
    Person person;
    person.PhoneNbr="0636757575";
    REQUIRE(person.hasValidPhoneNumber(person.PhoneNbr)==true);

    person.PhoneNbr="1636757575";
    REQUIRE_FALSE(person.hasValidPhoneNumber(person.PhoneNbr)==true);

    person.PhoneNbr="636757575";
    REQUIRE_FALSE(person.hasValidPhoneNumber(person.PhoneNbr)==true);

    person.Name = "Adrien";
    REQUIRE(person.hasValidName(person.Name)==true);

    person.Name = "1drien";
    REQUIRE_FALSE(person.hasValidName(person.Name)==true);

    person.Name = "";
    REQUIRE_FALSE(person.hasValidName(person.Name)==true);
}

/* ########################################################################## */
