#include "ClapTrap.hpp"

int main( void )
{
    ClapTrap clap("Fire");

    clap.attack("maomao");
    clap.takeDamage(9);
    clap.attack("maomao");
    clap.beRepaired(1);
    clap.takeDamage(2);
    clap.beRepaired(1);
    clap.attack("maomao");
}
