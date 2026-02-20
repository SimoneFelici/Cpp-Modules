#include "Span.hpp"
#include <iostream>

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    Span sp2(10000);
    for (int i = 0; i < 10000; ++i)
        sp2.addNumber(i);
    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;

    Span sp3(100);
    std::vector<int> vec;
    for (int i = 0; i < 100; ++i)
        vec.push_back(i * 10);
    sp3.addRange(vec.begin(), vec.end());
    std::cout << sp3.shortestSpan() << std::endl;
    std::cout << sp3.longestSpan() << std::endl;

    try {
        Span sp4(2);
        sp4.addNumber(1);
        sp4.addNumber(2);
        sp4.addNumber(3);
    } catch (std::exception& e) {
        std::cout << "Exception caught" << std::endl;
    }

    return 0;
}

/*
int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0;
}
*/
