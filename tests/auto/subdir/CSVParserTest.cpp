#include <iostream>

#include <test/catch.hpp>

#include "subdir/CSVParser.hpp"




/* ########################################################################## */
TEST_CASE("Test de l'overture du fichier","[OpenFile]"){
    CSVParser parser;
    
    REQUIRE(parser.initWithFile("../../../src/sondage.csv")==true);
    std::string *csvItems = new std::string[MAX_COLUMN];
    csvItems=parser.getLine(1);
    REQUIRE(csvItems[0] == "Prénoms");
    REQUIRE(csvItems[1] == "Numéros de téléphone");
    REQUIRE(csvItems[2] == "Réponses");
    REQUIRE(csvItems[3] == "Noms");
    

    csvItems = new std::string[MAX_COLUMN];
    csvItems = parser.getLine(2);
    REQUIRE(csvItems[0] == "Bastien");
    REQUIRE(csvItems[1] == "0612345678");
    REQUIRE(csvItems[2] == "4/18");
    REQUIRE(csvItems[3] == "Righi");
    
}


/* ########################################################################## */
