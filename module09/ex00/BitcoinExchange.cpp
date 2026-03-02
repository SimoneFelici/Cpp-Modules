#include "BitcoinExchange.hpp"
#include <algorithm>
#include <cctype>
#include <sstream>
#include <stdexcept>
#include <string>

BitcoinExchange::BitcoinExchange() { }

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
    : db(other.db)
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        db = other.db;
    return (*this);
}

BitcoinExchange::~BitcoinExchange() { }

void BitcoinExchange::printMap()
{
    for (std::map<std::string, double>::const_iterator it = this->db.begin(); it != this->db.end(); ++it)
        std::cout << it->first << " = " << it->second << "\n";

    std::cout << '\n';
}

bool BitcoinExchange::checkRate(const std::string& str, double& out)
{
    std::istringstream iss(str);
    char extra;

    if (!(iss >> out))
        return false;

    if (iss >> extra)
        return false;

    if (out < 0)
        return false;

    return true;
}

bool isAllDigits(const std::string& s)
{
    for (size_t i = 0; i < s.length(); ++i) {
        if (!std::isdigit(s[i]))
            return false;
    }
    return true;
}

bool BitcoinExchange::checkDate(const std::string& date)
{
    if (date.length() != 10)
        return false;

    if (date[4] != '-' || date[7] != '-')
        return false;

    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);

    if (!isAllDigits(yearStr) || !isAllDigits(monthStr) || !isAllDigits(dayStr))
        return false;

    int year;
    int month;
    int day;

    std::istringstream(yearStr) >> year;
    std::istringstream(monthStr) >> month;
    std::istringstream(dayStr) >> day;

    if (year < 0)
        return false;

    if (month < 1 || month > 12)
        return false;

    if (day < 1 || day > 31)
        return false;

    return true;
}

void BitcoinExchange::loadDB()
{
    std::string line;
    std::ifstream file_db("cpp_09/data.csv");
    std::string date;
    std::string rateStr;
    double rate;

    if (file_db.is_open()) {
        getline(file_db, line);
        if (line.compare("date,exchange_rate") != 0) {
            throw std::runtime_error("Incorrect CSV headers, Expected:\ndate,exchange_rate\n");
        }
        while (getline(file_db, line)) {
            date = line.substr(0, line.find(','));
            rateStr = line.substr(line.find(',') + 1);

            if (!checkDate(date))
                throw std::runtime_error("Invalid date in CSV: " + line);
            if (!checkRate(rateStr, rate))
                throw std::runtime_error("Invalid rate in CSV: " + line);

            db[date] = rate;
        }
        file_db.close();
    }

    else
        throw std::runtime_error("Unable to open db file");
}

bool is_not_space(char c)
{
    return !std::isspace(static_cast<unsigned char>(c));
}

void trim(std::string& str)
{
    str.erase(str.begin(), std::find_if(str.begin(), str.end(), is_not_space));
    str.erase(std::find_if(str.rbegin(), str.rend(), is_not_space).base(), str.end());
}

bool BitcoinExchange::checkValue(const std::string& str, double& out)
{
    std::istringstream iss(str);
    char extra;

    if (!(iss >> out))
        return false;

    if (iss >> extra)
        return false;

    if (out < 0 || out > 1000)
        return false;

    return true;
}

void BitcoinExchange::parseInput(std::string arg)
{
    std::ifstream input(arg.c_str());
    std::string line;
    std::string date;
    std::string rateStr;
    double rate;
    std::map<std::string, double>::iterator it;

    if (input.is_open()) {
        getline(input, line);
        if (line.compare("date | value") != 0) {
            throw std::runtime_error("Incorrect input headers, Expected:\ndate | value\n");
        }
        while (getline(input, line)) {
            date = line.substr(0, line.find('|'));
            trim(date);
            rateStr = line.substr(line.find('|') + 1);
            trim(rateStr);
            if (!checkDate(date)) {
                std::cout
                    << "Error: invalid date in input: " << date << '\n';
                continue;
            }
            if (!checkValue(rateStr, rate)) {
                std::cout << "Error: invalid value in input: " << rateStr << '\n';
                continue;
            }
            it = db.upper_bound(date);
            if (it == db.begin()) {
                std::cout << "Error: no exchange rate found for date: " << date << '\n';
                continue;
            }
            --it;
            std::cout << date << " => " << rate << " = " << it->second * rate << '\n';
        }
    } else
        throw std::runtime_error("Unable to open input file");
}
