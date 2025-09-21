#include "Zombie.hpp"

void randomChump(std::string n)
{
    Zombie z;
    z.setName(n);
    z.announce();
}
