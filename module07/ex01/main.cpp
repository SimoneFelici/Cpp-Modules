#include "iter.hpp"
#include <cctype>
#include <iostream>

template <typename T>
void printer(const T& c)
{
    std::cout << c << std::endl;
}

void add_num(int& num)
{
    num += 1;
}

void upper(char& c)
{
    c = std::toupper(c);
}

int main()
{
    int array_i[3] = { 3, 6, 9 };
    iter(array_i, 3, printer);
    iter(array_i, 3, add_num);
    iter(array_i, 3, printer);

    char string[] = "ciao";
    iter(string, 4, printer);
    iter(string, 4, upper);
    iter(string, 4, printer);
}
