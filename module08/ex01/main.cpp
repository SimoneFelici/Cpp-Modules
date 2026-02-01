#include "Span.hpp"
#include <iostream>

int main()
{
    Span a(5);
    try {
        a.addNumber(1);
        a.addNumber(9);
        a.addNumber(23);
        a.addNumber(65);
        a.addNumber(3);
    } catch (std::exception& e) {
        std::cout << "Exceeded size" << std::endl;
    }
    try {
        std::cout << "Shorted Span: " << a.shortestSpan() << std::endl;
        std::cout << "Longest Span:" << a.longestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cout << "Less than 2 values" << std::endl;
    }
}
