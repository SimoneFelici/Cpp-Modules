#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal()
{
    type = "Dog";
    std::cout << type << " Created!" << std::endl; 
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog Copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog& other)
{
    type = other.getType();
    std::cout << "Dog Copy assignment operator called" << std::endl;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Bau!" << std::endl;
}
