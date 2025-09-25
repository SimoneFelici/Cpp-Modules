#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

static void line() { std::cout << "-----------------------------\n"; }

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

    std::cout << "Create ScavTrap (base then derived construction):\n";
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

    std::cout << "Create FragTrap (base then derived construction):\n";
    {
        FragTrap f1("ClappyJr");
        f1.attack("Marauder");
        f1.highFivesGuys();

        std::cout << "Copy-construct FragTrap:\n";
        FragTrap f2(f1);
        f2.attack("Badass Nomad");

        std::cout << "Assign FragTrap:\n";
        FragTrap f3("TempFrag");
        f3 = f1;
        f3.takeDamage(40);
        f3.beRepaired(20);
        f3.attack("Skag Pup");
    }
    line();
}
