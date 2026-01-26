#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

ScalarConverter::ScalarConverter() { };
ScalarConverter::~ScalarConverter() { };
ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    *this = other;
};
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return (*this);
};

bool ScalarConverter::checkChar(const std::string& input)
{
    if (input.length() == 3) {
        if (input[0] == '\'' && input[2] == '\'') {
            return (1);
        }
    }
    return (0);
}

bool ScalarConverter::checkInt(const std::string& input)
{
    (void)input;
    return (0);
}

bool ScalarConverter::checkFloat(const std::string& input)
{
    (void)input;
    return (0);
}

bool ScalarConverter::checkDouble(const std::string& input)
{
    (void)input;
    return (0);
}

int ScalarConverter::findType(const std::string& input)
{
    if (!input[0])
        return (0);
    else if (checkChar(input))
        return (1);
    else if (checkInt(input))
        return (2);
    else if (checkFloat(input))
        return (3);
    else if (checkDouble(input))
        return (4);
    else
        return (0);
}

void printChar(char c)
{
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void printInt(int i)
{
    (void)i;
}

void printFloat(float f)
{
    (void)f;
}

void printDouble(double d)
{
    (void)d;
}

void ScalarConverter::convert(const std::string& input)
{
    int type = findType(input);

    switch (type) {
    case 1: {
        char c = input[1];
        printChar(c);
        break;
    }
    case 2: {
        int i = std::atoi(input.c_str());
        printInt(i);
        break;
    }
    case 3: {
        float f = std::atof(input.c_str());
        printFloat(f);
        break;
    }
    case 4: {
        double d = std::strtod(input.c_str(), NULL);
        printDouble(d);
        break;
    }
    default:
        std::cout << "Error: invalid input" << std::endl;
        break;
    }
}
