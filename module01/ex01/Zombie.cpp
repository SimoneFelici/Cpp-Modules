#include "Zombie.hpp"
#include <iostream>

std::string Zombie::getName(void)
{
    return name;
}

void Zombie::setName(std::string n)
{
    name = n;
}

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie destroyed: " << name << std::endl;
}
