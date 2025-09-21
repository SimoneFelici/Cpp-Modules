#include <iostream>
#include <iomanip>
#include <string>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << std::setw(22) << "address of string: " << &str << std::endl;
    std::cout << "address of stringPTR: " << stringPTR << std::endl;
    std::cout << "address of stringREF: " << &stringREF << std::endl;

    std::cout << std::endl;

    std::cout << std::setw(20) << "value of string: " << str << std::endl;
    std::cout << "value of stringPTR: " << *stringPTR << std::endl;
    std::cout << "value of stringREF: " << stringREF << std::endl;
}
