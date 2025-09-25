#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class FragTrap : public ClapTrap
{
    public:
        FragTrap(std::string n);
        FragTrap(const FragTrap& other);
        FragTrap &operator=(const FragTrap& other);
        ~FragTrap();

        void highFivesGuys(void);
};

#endif
