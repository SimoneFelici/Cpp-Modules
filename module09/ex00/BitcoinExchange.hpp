#pragma once

#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

class BitcoinExchange {
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();
    void loadDB();

    void checkInput();
    void parseInput();
    void printMap();

private:
    std::map<std::string, double> db;

    bool checkDate(const std::string& date);
    bool checkValue(const std::string& value);
    bool checkRate(const std::string& rate, double& out);
};

// std::ostream& operator<<(std::ostream& os, BitcoinExchange bit);
