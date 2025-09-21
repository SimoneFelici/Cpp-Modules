#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA {
    public:
        HumanA(const std::string &s, Weapon &wp);
        void attack();
    private:
        Weapon &weapon;
        std::string name;
};

#endif
