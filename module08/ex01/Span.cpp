#include "Span.hpp"
#include <exception>

Span::Span(unsigned int num)
    : N(num)
    , vec()
{
    vec.reserve(N);
};
Span::Span(const Span& other)
    : N(other.N)
    , vec()
{
    vec.reserve(N);
    vec = other.vec;
}

Span& Span::operator=(const Span& other)
{
    if (this != &other) {
        vec.reserve(N);
        vec = other.vec;
    }
    return (*this);
}

void Span::addNumber(int add)
{
    if (vec.size() >= N)
        throw std::exception();
    this->vec.push_back(add);
}

void Span::addRange(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
    if ((vec.size() + (end - start)) > N)
        throw std::exception();
    vec.insert(vec.end(), start, end);
}

const int& Span::operator[](unsigned int i) const
{
    if (vec.size() < i)
        throw std::exception();
    return vec[i];
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
