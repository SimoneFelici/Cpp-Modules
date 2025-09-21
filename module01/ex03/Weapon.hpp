#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
    public:
        Weapon(const std::string &value);
        const std::string &getType();
        void setType(const std::string &value);
    private:
        std::string type;
};

#endif
