#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(const std::string n) : ClapTrap(n)
{
    hit_point = 100;
    energy    = 100;
    dmg       = 30;
    std::cout << "FragTrap " << name << " Created" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    *this = other;
    std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    name      = other.name;
    hit_point = other.hit_point;
    energy    = other.energy;
    dmg       = other.dmg;

    std::cout << "FragTrap Copy assignment operator called" << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << name << " requests a high five!" << std::endl;
}
