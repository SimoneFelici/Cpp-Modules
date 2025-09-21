#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB {
    public:
        HumanB(const std::string &s);
        void attack();
        void setWeapon(Weapon &wp);
    private:
        std::string name;
        Weapon *weapon;
};

#endif
