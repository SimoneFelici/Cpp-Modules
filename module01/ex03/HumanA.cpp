#include "HumanA.hpp"
#include <iostream>

void HumanA::attack()
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}

HumanA::HumanA(const std::string &s, Weapon &wp) : weapon(wp)
{
    name = s;
}
