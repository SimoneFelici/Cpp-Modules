#include "Zombie.hpp"

int main()
{
    int i;
    int N = 15;
    Zombie *z = zombieHorde(N, "fire");
    
    for (i = 0; i < N; i++)
    {
        z[i].announce();
    }
    delete[] z;
}
