/**
 *  @file   CSVParser.hpp
 *  @brief  A simple csv parser.
 */
#ifndef CSVPARSER_HPP
#define CSVPARSER_HPP
#define MAX_COLUMN 4

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

struct CSVParser{
    std::string filepath;
    int numberOfColumns;
    int numberOfRows;
    std::vector<std::string> header;
    bool initWithFile(std::string path);
    std::string* getLine (int rowNum);
    std::string* getLineWithHighestRateOfResponses();
    std::string* getLineWithLastname(std::string name);
    std::string* getPersonWithLastname(std::string name);
};


#endif /*< CSVPARSER_HPP */
