#include <iostream>

#include <test/catch.hpp>

#include "subdir/CSVParser.hpp"




/* ########################################################################## */
TEST_CASE("Test de l'overture du fichier","[OpenFile]"){
    CSVParser parser;
    parser.numberOfRows = 22;
    parser.numberOfColumns = 4;
    REQUIRE(parser.initWithFile("../../../src/sondage.csv")==true);
    std::string *csvItems = new std::string[parser.numberOfColumns];
    csvItems=parser.getLine(1);
    REQUIRE(csvItems[0] == "Prénoms");
    REQUIRE(csvItems[1] == "Numéros de téléphone");
    REQUIRE(csvItems[2] == "Réponses");
    REQUIRE(csvItems[3] == "Noms");
    

    csvItems = new std::string[parser.numberOfColumns];
    csvItems = parser.getLine(2);
    REQUIRE(csvItems[0] == "Bastien");
    REQUIRE(csvItems[1] == "0612345678");
    REQUIRE(csvItems[2] == "4/18");
    REQUIRE(csvItems[3] == "Righi");

    csvItems = new std::string[parser.numberOfColumns]; 
    csvItems = parser.getLineWithHighestRateOfResponses();
    REQUIRE(csvItems[0] == "Rémi");
    REQUIRE(csvItems[1] == "0680737812");
    REQUIRE(csvItems[2] == "20/20");
    REQUIRE(csvItems[3] == "Berlioz");

    std::string **csvItemsArr = create2dArray(parser.numberOfRows,parser.numberOfColumns);
    csvItemsArr = parser.getLineWithLastname("Colombier");
    REQUIRE(csvItemsArr[0][0] == "Florent");
    REQUIRE(csvItemsArr[0][1] == "0434560690");
    REQUIRE(csvItemsArr[0][2] == "18/19");
    REQUIRE(csvItemsArr[0][3] == "Colombier");
    REQUIRE(csvItemsArr[1][0] == "Jean-Marc");
    REQUIRE(csvItemsArr[1][1] == "0643219401");
    REQUIRE(csvItemsArr[1][2] == "13/18");
    REQUIRE(csvItemsArr[1][3] == "Colombier");
    REQUIRE(csvItemsArr[2][0] == "Cedric");
    REQUIRE(csvItemsArr[2][1] == "0667836312");
    REQUIRE(csvItemsArr[2][2] == "11/13");
    REQUIRE(csvItemsArr[2][3] == "Colombier");
    REQUIRE(csvItemsArr[3][0] == "Thomas");
    REQUIRE(csvItemsArr[3][1] == "0680138353");
    REQUIRE(csvItemsArr[3][2] == "14/15");
    REQUIRE(csvItemsArr[3][3] == "Colombier");

    Person *person = new Person[parser.numberOfRows];
    person = parser.getPersonWithLastname("Colombier");
    Fraction fraction0(18,19),fraction1(13,18),fraction2(11,13),fraction3(14,15);
    REQUIRE(person[0].FirstName == "Florent");
    REQUIRE(person[0].PhoneNbr == "0434560690");
    REQUIRE((person[0].Answer == fraction0)==true);
    REQUIRE(person[0].LastName == "Colombier");
    REQUIRE(person[1].FirstName == "Jean-Marc");
    REQUIRE(person[1].PhoneNbr == "0643219401");
    REQUIRE((person[1].Answer == fraction1)==true);
    REQUIRE(person[1].LastName == "Colombier");
    REQUIRE(person[2].FirstName == "Cedric");
    REQUIRE(person[2].PhoneNbr == "0667836312");
    REQUIRE((person[2].Answer == fraction2)==true);;
    REQUIRE(person[2].LastName == "Colombier");
    REQUIRE(person[3].FirstName == "Thomas");
    REQUIRE(person[3].PhoneNbr == "0680138353");
    REQUIRE((person[3].Answer == fraction3)==true);
    REQUIRE(person[3].LastName == "Colombier");
}


/* ########################################################################## */
