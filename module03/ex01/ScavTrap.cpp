#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string n) : ClapTrap(n)
{
    hit_point = 100;
    energy = 50;
    dmg = 20;
    std::cout << "ScavTrap " << n << " Created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    *this = other;
    std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap& other)
{
    name = other.name;
    hit_point = other.hit_point;
    energy = other.energy;
    dmg = other.dmg;
    std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (hit_point <= 0)
    {
        std::cout << "ScavTrap " << name << " is dead." << std::endl;
        return;
    }
    if (energy <= 0)
    {
        std::cout << "ScavTrap " << name << " is out of energy." << std::endl;
        return;
    }
    std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << dmg << " points of damage!" << std::endl;
    --energy;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is now in gate keeper mode!" << std::endl;
}
