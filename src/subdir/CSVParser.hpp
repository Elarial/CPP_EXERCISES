/**
 *  @file   CSVParser.hpp
 *  @brief  A not so simple csv parser.
 */
#ifndef CSVPARSER_HPP
#define CSVPARSER_HPP
#define FIRST_DATA_LINE 2

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Person.hpp"

enum csvColumnsEnum : const int{
    firstNameColumn = 0,
    phoneNbrColumn = 1,
    answerColumn = 2,
    lastNameColumn = 3
};

struct CSVParser{
    //Path of the csv file.
    std::string filepath ="";
    //Number of columns of the vsb file
    int numberOfColumns = 0;
    //Number of rows of the csv file
    int numberOfRows = 0;
    //Separator of the csv file.
    char separator;
    //Header of the csv file
    std::string* header;
    //Collection size for a querry like getLineWithLastname
    int collectionSize = 0;

    //Initialize CSVParser object with basic elements
    bool initWithFile(std::string path);
    
    //Return the line nbr in param, header excluded
    std::string* getLine (int rowNum);

    //Return the line with the highest rate of responses.
    //If more than one line is elligible, only the first will be returned.
    std::string* getLineWithHighestRateOfResponses();

    //Return a 2d array with the name matching the parameter
    std::string** getLineWithLastname(const std::string name);

    //Return a array of person with the name matching the parameter
    Person* getPersonWithLastname(const std::string name);
    
    enum sep_t{
        CSV_COMMA = 0,
        CSV_SEMICOLON,
        CSV_TABULATION,
        CSV_4SPACES
    };

    sep_t getSeparatorType();
};

//Allow to create a 2d array
std::string** create2dArray (const unsigned height,const unsigned width);

#endif /*< CSVPARSER_HPP */
