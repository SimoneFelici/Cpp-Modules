#include "Span.hpp"

Span::Span(unsigned int num)
    : N(num)
    , vec(0) {

    };
Span::Span(const Span& other)
    : N(other.N)
    , vec(other.vec) {

    };
Span& Span::operator=(const Span& other)
{
    N = other.N;
    this->vec = other.vec;
    return (*this);
};

void Span::addNumber(int add)
{
    if (N == 0)
        throw std::exception();
    this->vec.push_back(add);
    --N;
}

unsigned int Span::shortestSpan()
{
    if (vec.size() < 2)
        throw std::exception();
    std::vector<int> sorted(vec.begin(), vec.end());
    std::sort(sorted.begin(), sorted.end());

    int minSpan = sorted[1] - sorted[0];
    for (size_t i = 2; i < sorted.size(); ++i) {
        minSpan = std::min(minSpan, sorted[i] - sorted[i - 1]);
    }
    return (minSpan);
}

unsigned int Span::longestSpan()
{
    if (vec.size() < 2)
        throw std::exception();
    std::vector<int> sorted(vec.begin(), vec.end());
    std::sort(sorted.begin(), sorted.end());

    return (sorted.back() - sorted.front());
}
