/**
 *  @file   CSVParser.cpp
 *  @brief  Source file of the csv parser.
 *  Note that arrays are mandatory in the exercice and lead to complex pieces of code.
 *  Vector would have been much more simple.
 */
#include "CSVParser.hpp"

/* ########################################################################## */
bool CSVParser::initWithFile(std::string path)
{
    this->filepath = path;
    std::ifstream fichier(path.c_str());
    std::string s;

    switch (this->getSeparatorType())
    {
        case CSV_COMMA:
            this->separator=',';
            break;
        case CSV_SEMICOLON:
            this->separator=';';
            break;
        case CSV_TABULATION:
            this->separator = '\t';
            break;
        case CSV_4SPACES:
            this->separator = ' ';
            break;        
        default:
            break;
    }
    if (!fichier.good())
    {
        std::cerr << "Une erreur est survenue lors de l'ouverture du fichier " + path << std::endl;
        fichier.close();
        return false;
    }
    //Compute number of row :
    //First, get one line
    std::getline(fichier,s);
    //Change this line into stream object is usefull for iteration.
    std::istringstream myLine(s);
    //add a column each time a separator is seen.
    while (std::getline(myLine,s,this->separator)){
        this->numberOfColumns++;
    }

    //Initialize the header
    this->header = new std::string[this->numberOfColumns];
    //Set the cursor at the begining
    myLine.clear();
    myLine.seekg(0);
    //Feed the header
    for(int i = 0; i < this->numberOfColumns; i++)
    {
        std::getline(myLine, this->header[i], this->separator);
    }
    //Count the number of row, header excluded.
    while(std::getline(fichier,s)){
        this->numberOfRows++;
    }
    
    fichier.close();
    return true;
}


std::string* CSVParser::getLine(int rowNum)
{
    if (rowNum > this -> numberOfRows){
        std::cerr << "L'argument rowNum =" << rowNum << "est superieur au nombre de lignes =" << this -> numberOfRows << std::endl;
        return NULL;
    }
    std::string *csvItems = new std::string[this->numberOfColumns];
    int lineNumber = 0;
    std::string line;
    std::ifstream fichier(this->filepath);

    if (fichier.is_open())
    {
        //Header is excluded from getLine => Cursor position is placed after header.
        std::getline(fichier, line); 
        
        //Iteration though the file, finding the desired line.
        while (std::getline(fichier, line))
        {
            if (lineNumber+1 == rowNum)
            {
                std::istringstream myLine(line);
                for (int i = 0; i < this->numberOfColumns; i++)
                {
                    std::getline(myLine, csvItems[i], this->separator);
                }
                fichier.close();
                return csvItems;
            }
            lineNumber++;
        }
        std::cerr << "Impossible de trouver la ligne " << rowNum << std::endl;
        fichier.close();
        return NULL;
    }
    std::cerr << "Erreur lors de l'ouverture du fichier" << std::endl;
    fichier.close();
    return NULL;
}

//Finding the highest rate of responses
//Note that only one line is returned
//If more than one line have highestRate, only the first seen will be returned.
std::string* CSVParser::getLineWithHighestRateOfResponses(){

    int highestIndex = 0;
    Fraction highestFrac(0,1),tmpFrac(0,1);
    std::string *csvItems = new std::string[this->numberOfColumns];

    for (int i = 1; i <= this->numberOfRows; i++)
    {
        //Find the line with the highest rate
        csvItems = this->getLine(i);
        tmpFrac = strToFrac(csvItems[answerColumn]);
        if(tmpFrac > highestFrac){
            highestFrac = tmpFrac;
            highestIndex = i;
        }
    }
    //Return the line with the highest rate
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
    int rowIndex = 0;

    //Iterate trough each line
    for(int i = 1; i <= this->numberOfRows; i++)
    {
       csvItems = this->getLine(i);

        //Find the predicat
        if(csvItems[lastNameColumn] == name){
            //Feed the 2d array
            csvItemsArr[rowIndex]=csvItems;
            rowIndex++;
            
        }
        
    }
    this->collectionSize = rowIndex;
    return csvItemsArr;
    
}


Person* CSVParser::getPersonWithLastname(const std::string name){
    std::string **csvItemsArr = create2dArray(this->numberOfRows,this->numberOfColumns);
    csvItemsArr = getLineWithLastname(name);
    Person *person = new Person[this->collectionSize];

    //Iterate trough the collection
    for(int i = 0; i < this->collectionSize; i++)
    {
        //Feed the person array
        person[i].FirstName = csvItemsArr[i][firstNameColumn];
        person[i].Answer = strToFrac(csvItemsArr[i][answerColumn]);
        person[i].PhoneNbr = csvItemsArr[i][phoneNbrColumn];
        person[i].LastName = csvItemsArr[i][lastNameColumn];
    }
    

    //cleaning memory
    for (int h = 0; h < this->numberOfRows; h++)
    {
        delete[] csvItemsArr[h];
    }
    delete[] csvItemsArr;
    csvItemsArr = 0;
    
    return person;
}

CSVParser::sep_t CSVParser::getSeparatorType(){
    std::string separators[] {",",";","\t","    "};
    std::string line;
    std::ifstream fichier(this->filepath);
    //Get the first line
    std::getline(fichier,line);
    //For each separator
    for(size_t i = 0; i < 4; i++)
    {   //search if it exists in the line
        if(line.find(separators[i]) != std::string::npos){
            //return casted enum.
            return (sep_t)i;
        }
    }
    //Note that multiple separators is not handled, the first separator seen will be considered as the separator file.
    std::cerr << "Aucun séparateur trouvé dans le fichier, la virgule sera utilisé par défaut" << std::endl;
    return CSV_COMMA;
}
/* ########################################################################## */
