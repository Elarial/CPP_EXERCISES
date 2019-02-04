/**
 *  @file   CSVParser.hpp
 *  @brief  A simple csv parser.
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
    std::string filepath;
    int numberOfColumns;
    int numberOfRows;
    std::string* header;
    bool initWithFile(std::string path);
    std::string* getLine (int rowNum);
    std::string* getLineWithHighestRateOfResponses();
    std::string** getLineWithLastname(const std::string name);
    Person* getPersonWithLastname(const std::string name);
};
std::string** create2dArray (const unsigned height,const unsigned width);

#endif /*< CSVPARSER_HPP */
