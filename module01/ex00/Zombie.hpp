#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
    public:
        Zombie();
        ~Zombie();
        std::string getName(void);
        void setName(std::string n);
        void announce(void);
    private:
        std::string name;
};

Zombie* newZombie(std::string n);
void randomChump(std::string n);

#endif
