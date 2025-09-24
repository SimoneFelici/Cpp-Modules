#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : value(0){}

Fixed::Fixed(const int n) : value(n << fractional_num){}

Fixed::Fixed(const float f)
{
    const int scale = 1 << fractional_num;

    value = static_cast<int>(::roundf(f * scale));
}

Fixed::Fixed(const Fixed& other)
{
    *this = other;
}

Fixed &Fixed::operator=(const Fixed& other)
{
    value = other.value;
    return *this;
}

Fixed::~Fixed(){}

bool Fixed::operator>(const Fixed& other) const
{
    return value > other.value;
}
bool Fixed::operator<(const Fixed& other) const
{
    return value < other.value;
}
bool Fixed::operator>=(const Fixed& other) const
{
    return value >= other.value;
}
bool Fixed::operator<=(const Fixed& other) const
{
    return value <= other.value;
}
bool Fixed::operator==(const Fixed& other) const
{
    return value == other.value;
}
bool Fixed::operator!=(const Fixed& other) const
{
    return value != other.value;
}

Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed r;
    r.value = this->value + other.value;
    return r;
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed r;

    r.value = this->value - other.value;
    return r;
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed r;

    long long prod = static_cast<long long>(this->value) * static_cast<long long>(other.value);
    r.value = static_cast<int>(prod >> fractional_num);
    return r;
}

Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed r;
    long long num = (static_cast<long long>(this->value) << fractional_num);
    r.value = static_cast<int>(num / static_cast<long long>(other.value));
    return r;
}

Fixed& Fixed::operator++()
{
    ++value;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    ++(*this);
    return tmp;
}

Fixed& Fixed::operator--()
{
    --value;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    --(*this);
    return tmp;
}

int Fixed::getRawBits(void) const
{
    return value;
}

void Fixed::setRawBits(int const raw)
{
    value = raw;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(value) / static_cast<float>(1 << fractional_num);
}

int Fixed::toInt(void) const
{
    return value >> fractional_num;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a < b)
        return a;
    return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a < b)
        return a;
    return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a > b)
        return a;
    return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a > b)
        return a;
    return b;
}


std::ostream& operator<<(std::ostream& os, const Fixed& fx)
{
    os << fx.toFloat();
    return os;
}
