/**
 *  @file   MyClass.cpp
 *  @brief  Demo source for C++ project template.
 */
#include "CSVParser.hpp"




/* ########################################################################## */
/* ########################################################################## */
bool CSVParser::initWithFile(std::string chemin_fichier){
    this->filepath = chemin_fichier;
    std::ifstream fichier(chemin_fichier.c_str());

    if (!fichier.good()){
        std::cerr << "Une erreur est survenue lors de l'ouverture du fichier "+chemin_fichier << std::endl;
        return false;
    }
    return true;
}
/* ########################################################################## */
/* ########################################################################## */
