#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
    public:
        ClapTrap(std::string n);
        ClapTrap(const ClapTrap& other);
        ClapTrap &operator=(const ClapTrap& other);
        ~ClapTrap();

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
    private:
        std::string name;
        int hit_point;
        int energy;
        int dmg;
};

#endif
