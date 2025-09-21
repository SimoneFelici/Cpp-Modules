#include "Zombie.hpp"

int main()
{
    Zombie* z = newZombie("heap");
    z->announce();
    delete z;

    randomChump("stack");
}
