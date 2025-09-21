#include "Zombie.hpp"

int main()
{
    int i;
    Zombie *z = zombieHorde(5, "fire");
    
    for (i = 0; i < 5; i++)
    {
        z[i].announce();
    }
    delete[] z;
}
