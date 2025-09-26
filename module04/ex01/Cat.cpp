#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal(), brain(new Brain())
{
    type = "Cat";
    std::cout << type << " Created!" << std::endl; 
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain))
{
    std::cout << "Cat Copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        Brain* nb = new Brain(*other.brain);
        delete brain;
        brain = nb;
    }
    std::cout << "Cat Copy assignment operator called" << std::endl;
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called" << std::endl;
    delete brain;
}

void Cat::makeSound() const
{
    std::cout << "Miao!" << std::endl;
}

void Cat::setIdea(int idx, const std::string& idea)
{
    brain->setIdea(idx, idea);
}
const std::string& Cat::getIdea(int idx) const
{
    return brain->getIdea(idx);
}
