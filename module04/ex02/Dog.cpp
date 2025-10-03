#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal(), brain(new Brain())
{
    type = "Dog";
    std::cout << type << " Created!" << std::endl; 
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain))
{
    std::cout << "Dog Copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        Brain* newBrain = new Brain(*other.brain);
        delete brain;
        brain = newBrain;
    }
    std::cout << "Dog Copy assignment operator called" << std::endl;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called" << std::endl;
    delete brain;
}

void Dog::makeSound() const
{
    std::cout << "Bau!" << std::endl;
}

void Dog::setIdea(int idx, const std::string& idea)
{
    brain->setIdea(idx, idea);
}
const std::string& Dog::getIdea(int idx) const
{
    return brain->getIdea(idx);
}
