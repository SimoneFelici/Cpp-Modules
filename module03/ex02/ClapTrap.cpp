#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string n) : name(n), hit_point(10), energy(10), dmg(0)
{
    std::cout << "ClapTrap " << n << " Created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    *this = other;
    std::cout << "Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& other)
{
    name = other.name;
    hit_point = other.hit_point;
    energy = other.energy;
    dmg = other.dmg;
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (hit_point <= 0)
    {
        std::cout << "ClapTrap " << name << " is dead." << std::endl;
        return;
    }
    if (energy <= 0)
    {
        std::cout << "ClapTrap " << name << " is out of energy." << std::endl;
        return;
    }
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << dmg << " points of damage!" << std::endl;
    --energy;
}
void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << name << " takes " << amount << " damage." << std::endl;
    hit_point -= amount;
    if (hit_point < 0)
        hit_point = 0;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (hit_point <= 0)
    {
        std::cout << "ClapTrap " << name << " is dead." << std::endl;
        return;
    }
    if (energy <= 0)
    {
        std::cout << "ClapTrap " << name << " is out of energy." << std::endl;
        return;
    }
    hit_point += static_cast<int>(amount);
    --energy;
    std::cout << "ClapTrap " << name << " repairs " << amount << " HP" << std::endl;
}
