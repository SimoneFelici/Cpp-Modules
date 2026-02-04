#pragma once
#include <algorithm>
#include <exception>
#include <vector>

#include <iostream>

class Span {
public:
    Span(unsigned int num);
    Span(const Span& other);
    Span& operator=(const Span& other);
    void addNumber(int add);
    void addRange(std::vector<int>::iterator start, std::vector<int>::iterator end);
    unsigned int shortestSpan();
    unsigned int longestSpan();

    const int& operator[](unsigned int i) const;

private:
    const unsigned int N;
    std::vector<int> vec;
};
