/**
 *  @file   CSVParser.hpp
 *  @brief  A simple csv parser.
 */
#ifndef CSVPARSER_HPP
#define CSVPARSER_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

struct CSVParser{
    std::string filepath;
    int numberOfColumns;
    int numberOfRows;
    std::vector<std::string> header;
    bool initWithFile(std::string path);
};


#endif /*< CSVPARSER_HPP */
