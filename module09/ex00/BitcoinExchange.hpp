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
    void checkDB();
    void checkInput();
    void loadDB();
    void parseInput();

private:
    std::map<std::string, float> db;

    bool checkDate(const std::string& date);
    bool checkValue(const std::string& value);
    bool checkRate(const std::string& rate, float& out);
};

// std::ostream& operator<<(std::ostream& os, BitcoinExchange bit);
