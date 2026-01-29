#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base* generate(void)
{
    int i = 0;
    srand(time(0) + std::clock());
    i = std::rand() % 3;

    if (i == 0) {
        std::cout << "A created!" << std::endl;
        return (new (A));
    } else if (i == 1) {
        std::cout << "B created!" << std::endl;
        return (new (B));
    } else {
        std::cout << "C created!" << std::endl;
        return (new (C));
    }
}

// Prints type of the object pointed by p
void identify(Base* p)
{
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "A class" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "B class" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "C class" << std::endl;
}

// Prints type of the object referenced by p
void identify(Base& p)
{
    Base& ref = p;

    try {
        ref = dynamic_cast<A&>(p);
        std::cout << "A class" << std::endl;
        return;

    } catch (std::exception& e) {
    }
    try {
        ref = dynamic_cast<B&>(p);
        std::cout << "B class" << std::endl;
    } catch (std::exception& e) {
    }

    try {
        ref = dynamic_cast<C&>(p);
        std::cout << "C class" << std::endl;
    } catch (std::exception& e) {
    }
}

int main()
{
    Base* miao = generate();
    identify(miao);
    identify(*miao);
    delete miao;
}
