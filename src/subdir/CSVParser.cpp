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


std::string* CSVParser::getLine(int rowNum)
{
    std::string *csvItems = new std::string[this->numberOfColumns];
    int lineNumber = 0;
    std::string line;
    std::ifstream fichier(this->filepath);

    if (fichier.is_open())
    {
        //todo : for loop limiting to numberOfRows iterations.
        while (std::getline(fichier, line))
        {
            lineNumber++;
            if (lineNumber == rowNum)
            {
                std::istringstream myLine(line);
                for (int i = 0; i < this->numberOfColumns; i++)
                {
                    std::getline(myLine, csvItems[i], ',');
                }
                fichier.close();
                return csvItems;
            }
            
        }
        std::cerr << "Impossible de trouver la ligne " << rowNum << std::endl;
        fichier.close();
        return NULL;
    }
    std::cerr << "Erreur lors de l'ouverture du fichier" << std::endl;
    fichier.close();
    return NULL;
}

//todo manage case where 2 or more lines have highestRate.
std::string* CSVParser::getLineWithHighestRateOfResponses(){

    int ctr = FIRST_DATA_LINE,highestIndex = 0;
    Fraction highestFrac(0,1),tmpFrac(0,1);
    std::string *csvItems = new std::string[this->numberOfColumns];

    while(this->getLine(ctr)){
        csvItems = this->getLine(ctr);
        tmpFrac = strToFrac(csvItems[answerColumn]);

        if(tmpFrac > highestFrac){
            highestFrac = tmpFrac;
            highestIndex = ctr;
        }
        ctr++;
    }
    return this -> getLine (highestIndex);

}
std::string** create2dArray (const unsigned height,const unsigned width){

      std::string** array2d = 0;
      array2d = new std::string*[height];

      for (size_t h = 0; h < height; h++)
      {
            array2d[h] = new std::string[width];

            for (size_t w = 0; w < width; w++)
            {
                  array2d[h][w] = w + width * h;
            }
      }

      return array2d;
}
std::string** CSVParser::getLineWithLastname(const std::string name){

    std::string **csvItemsArr = create2dArray(this->numberOfRows,this->numberOfColumns);
    std::string *csvItems = new std::string[this->numberOfColumns];
    int ctr = FIRST_DATA_LINE,rowIndex = 0;

    while(this->getLine(ctr)){
        csvItems = this->getLine(ctr);
        if(csvItems[lastNameColumn] == name){
            csvItemsArr[rowIndex]=csvItems;
            rowIndex++;
        }
        ctr++;
    }
    return csvItemsArr;
    
}
Person* CSVParser::getPersonWithLastname(const std::string name){
    std::string **csvItemsArr = create2dArray(this->numberOfRows,this->numberOfColumns);
    Person *person = new Person[this->numberOfRows];


    //cleaning memory
    for (int h = 0; h < this->numberOfRows; h++)
    {
        delete[] csvItemsArr[h];
    }
    delete[] csvItemsArr;
    csvItemsArr = 0;
    return person;
}
/* ########################################################################## */
