#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
    public:
        ~Zombie();
        std::string getName(void);
        void setName(std::string n);
        void announce(void);
    private:
        std::string name;
};

Zombie* zombieHorde(int N, std::string name);

#endif
