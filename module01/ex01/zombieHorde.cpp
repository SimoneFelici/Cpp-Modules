#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    int i;
    Zombie *z = new Zombie[N];

    for (i = 0; i < N; i++)
    {
        z[i].setName(name);
    }
    return z;
}
