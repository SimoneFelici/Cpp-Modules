#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

static void line()
{
    std::cout << "-----------------------------\n";
}

int main()
{
    line();
    std::cout << "Create ClapTrap:\n";
    {
        ClapTrap c1("Fire");
        c1.attack("Maomao");
        c1.takeDamage(9);
        c1.attack("Maomao");
        c1.takeDamage(1);
        c1.beRepaired(1);
        c1.attack("Maomao");
    }
    line();

    std::cout << "Create ScavTrap (shows base then derived construction):\n";
    {
        ScavTrap s1("Scrappy");
        s1.attack("Bandit");
        s1.guardGate();

        std::cout << "Copy-construct ScavTrap:\n";
        ScavTrap s2(s1);
        s2.attack("Psycho");

        std::cout << "Assign ScavTrap:\n";
        ScavTrap s3("Temp");
        s3 = s1;
        s3.takeDamage(30);
        s3.beRepaired(10);
        s3.attack("Skag");
    }
    line();

    return 0;
}
