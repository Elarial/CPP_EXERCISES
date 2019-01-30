#include <iostream>

#include <test/catch.hpp>

#include "subdir/CSVParser.hpp"




/* ########################################################################## */
TEST_CASE("Test de l'overture du fichier","[OpenFile]"){
    CSVParser parser;
    REQUIRE(parser.initWithFile("sondage.csv")==true);
}

/* ########################################################################## */
