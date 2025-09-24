#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) : value(n << fractional_num)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) : value(static_cast<int>(roundf(f * (1 << fractional_num))))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    value = other.value;
    return *this;
}
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
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

std::ostream& operator<<(std::ostream& os, const Fixed& fx)
{
    os << fx.toFloat();
    return os;
}
