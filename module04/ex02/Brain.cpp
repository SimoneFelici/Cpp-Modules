#include "Brain.hpp"
#include <iostream>
#include <string>

Brain::Brain()
{
    std::cout << "Brain created" << std::endl; 
}

Brain::Brain(const Brain& other)
{
    *this = other;
    std::cout << "Brain Copy constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain& other)
{
    for (int i = 0; i < 100; ++i)
        ideas[i] = other.ideas[i];
    std::cout << "Brain Copy assignment operator called" << std::endl;
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain Destructor called" << std::endl;
}

void Brain::setIdea(int idx, const std::string& idea)
{
    if (idx < 0 || idx >= 100)
    {
        std::cout << "Out of bound" << std::endl;
        return;
    }
    ideas[idx] = idea;
}

const std::string& Brain::getIdea(int idx) const
{
    static const std::string empty;

    if (idx < 0 || idx >= 100)
    {
        std::cout << "Out of bound" << std::endl;
        return empty;
    }
    return ideas[idx];
}
