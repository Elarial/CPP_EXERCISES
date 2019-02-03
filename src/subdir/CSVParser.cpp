/**
 *  @file   CSVParser.cpp
 *  @brief  Source file of the csv parser.
 */
#include "CSVParser.hpp"

/* ########################################################################## */
bool CSVParser::initWithFile(std::string path)
{
    this->filepath = path;
    std::ifstream fichier(path.c_str());

    if (!fichier.good())
    {
        std::cerr << "Une erreur est survenue lors de l'ouverture du fichier " + path << std::endl;
        fichier.close();
        return false;
    }
    fichier.close();
    return true;
}

//Finish function by returning string*
std::string* CSVParser::getLine(int rowNum)
{
    std::string *csvItems = new std::string[MAX_COLUMN];
    int lineNumber = 0;
    std::string line;
    std::ifstream fichier(this->filepath);

    if (fichier.is_open())
    {
        while (std::getline(fichier, line))
        {
            lineNumber++;
            if (lineNumber == rowNum)
            {
                std::istringstream myLine(line);
                for (size_t i = 0; i < MAX_COLUMN; i++)
                {
                    std::getline(myLine, csvItems[i], ',');
                }
                return csvItems;
            }
            
        }
        std::cerr << "Impossible de trouver la ligne " << rowNum << std::endl;
            return NULL;
    }
    std::cerr << "Erreur lors de l'ouverture du fichier" << std::endl;
    return NULL;
}
/* ########################################################################## */
