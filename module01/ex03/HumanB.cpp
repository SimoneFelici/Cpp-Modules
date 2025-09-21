#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

void HumanB::attack()
{
    if (weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " has no weapon" << std::endl;
}

HumanB::HumanB(const std::string &s) : name(s), weapon(NULL){};

void HumanB::setWeapon(Weapon &wp)
{
    weapon = &wp;
}
