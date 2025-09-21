#include "Weapon.hpp"

const std::string &Weapon::getType()
{
    return (type);
}

void Weapon::setType(const std::string &value)
{
    type = value;
}

Weapon::Weapon(const std::string &s)
{
    setType(s);
}
