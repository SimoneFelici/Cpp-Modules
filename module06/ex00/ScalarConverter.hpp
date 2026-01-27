#pragma once
#include <string>

class ScalarConverter {
public:
    static void convert(const std::string& input);

private:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);

    static int findType(const std::string& input);
    static bool checkChar(const std::string& input);
    static bool checkInt(const std::string& input);
    static bool checkFloat(const std::string& input);
    static bool checkDouble(const std::string& input);

    static void printAll(double value, bool isSpecial);
    static void printImpossible();
};
