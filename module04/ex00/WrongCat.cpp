#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal()
{
    type = "WrongCat";
    std::cout << type << " Created!" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    std::cout << "WrongCat Copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    if (this != &other)
        WrongAnimal::operator=(other);
    std::cout << "WrongCat Copy assignment operator called" << std::endl;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "Chip chip" << std::endl;
}
