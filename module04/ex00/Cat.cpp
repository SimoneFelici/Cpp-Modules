#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal()
{
    type = "Cat";
    std::cout << type << " Created!" << std::endl; 
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Cat Copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat& other)
{
    type = other.getType();
    std::cout << "Cat Copy assignment operator called" << std::endl;
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Miao!" << std::endl;
}
