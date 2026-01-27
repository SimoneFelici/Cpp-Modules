#include "ScalarConverter.hpp"
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>

ScalarConverter::ScalarConverter() { }
ScalarConverter::~ScalarConverter() { }
ScalarConverter::ScalarConverter(const ScalarConverter& other) { *this = other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return (*this);
}

bool ScalarConverter::checkChar(const std::string& input)
{
    return (input.length() == 3 && input[0] == '\'' && input[2] == '\'');
}

bool ScalarConverter::checkInt(const std::string& input)
{
    size_t i = 0;
    if (input[i] == '+' || input[i] == '-')
        i++;
    if (i >= input.length())
        return false;
    while (i < input.length()) {
        if (!std::isdigit(input[i]))
            return false;
        i++;
    }
    return true;
}

bool ScalarConverter::checkFloat(const std::string& input)
{
    if (input == "nanf" || input == "+inff" || input == "-inff" || input == "inff")
        return true;
    if (input.empty() || input[input.length() - 1] != 'f')
        return false;

    std::string num = input.substr(0, input.length() - 1);
    size_t i = 0;
    bool hasDot = false;

    if (num[i] == '+' || num[i] == '-')
        i++;
    if (i >= num.length())
        return false;

    while (i < num.length()) {
        if (num[i] == '.') {
            if (hasDot)
                return false;
            hasDot = true;
        } else if (!std::isdigit(num[i])) {
            return false;
        }
        i++;
    }
    return hasDot;
}

bool ScalarConverter::checkDouble(const std::string& input)
{
    if (input == "nan" || input == "+inf" || input == "-inf" || input == "inf")
        return true;

    size_t i = 0;
    bool hasDot = false;

    if (input[i] == '+' || input[i] == '-')
        i++;
    if (i >= input.length())
        return false;

    while (i < input.length()) {
        if (input[i] == '.') {
            if (hasDot)
                return false;
            hasDot = true;
        } else if (!std::isdigit(input[i])) {
            return false;
        }
        i++;
    }
    return hasDot;
}

int ScalarConverter::findType(const std::string& input)
{
    if (input.empty())
        return 0;
    if (checkChar(input))
        return 1;
    if (checkInt(input))
        return 2;
    if (checkFloat(input))
        return 3;
    if (checkDouble(input))
        return 4;
    return 0;
}

void ScalarConverter::printAll(double value, bool isSpecial)
{
    // CHAR
    if (isSpecial || value < 0 || value > 127) {
        std::cout << "char: impossible" << std::endl;
    } else if (value < 32 || value >= 127) {
        std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    }

    // INT
    if (isSpecial || value > INT_MAX || value < INT_MIN) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    }

    // FLOAT
    std::cout << "float: " << static_cast<float>(value);
    if (!isSpecial && value == static_cast<int>(value)) {
        std::cout << ".0f" << std::endl;
    } else {
        std::cout << "f" << std::endl;
    }

    // DOUBLE
    std::cout << "double: " << value;
    if (!isSpecial && value == static_cast<int>(value)) {
        std::cout << ".0" << std::endl;
    } else {
        std::cout << std::endl;
    }
}

void ScalarConverter::printImpossible()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::convert(const std::string& input)
{
    int type = findType(input);
    double value = 0.0;
    bool isSpecial = false;

    switch (type) {
    case 1: { // CHAR
        value = static_cast<double>(input[1]);
        break;
    }
    case 2: { // INT
        long tmp = std::atol(input.c_str());
        if (tmp > INT_MAX || tmp < INT_MIN) {
            printImpossible();
            return;
        }
        value = static_cast<double>(tmp);
        break;
    }
    case 3: { // FLOAT
        value = static_cast<double>(std::atof(input.c_str()));
        isSpecial = (std::isnan(value) || std::isinf(value));
        break;
    }
    case 4: { // DOUBLE
        value = std::strtod(input.c_str(), NULL);
        isSpecial = (std::isnan(value) || std::isinf(value));
        break;
    }
    default: {
        printImpossible();
        return;
    }
    }

    printAll(value, isSpecial);
}
