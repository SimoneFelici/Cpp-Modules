#pragma once
#include <algorithm>
#include <exception>
#include <vector>

class Span {
public:
    Span(unsigned int num);
    Span(const Span& other);
    Span& operator=(const Span& other);
    void addNumber(int add);
    unsigned int shortestSpan();
    unsigned int longestSpan();

private:
    unsigned int N;
    std::vector<int> vec;
};
