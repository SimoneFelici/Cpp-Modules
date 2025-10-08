#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;

    std::cout << "\n--- Array test ---\n";
    const int N = 10;
    Animal* animals[N];

    for (int idx = 0; idx < N; ++idx)
    {
        if (idx < N/2)
            animals[idx] = new Dog();
        else
            animals[idx] = new Cat();
    }

    for (int idx = 0; idx < N; ++idx)
        delete animals[idx];

    std::cout << "\n--- Deep copy test ---\n";
    Dog d1;
    d1.setIdea(0, "Chase ball");
    Dog d2(d1);
    d1.setIdea(0, "Chew bone");
    std::cout << "d1[0]: " << d1.getIdea(0) << std::endl;
    std::cout << "d2[0]: " << d2.getIdea(0) << std::endl;

    Cat c1;
    c1.setIdea(0, "Sleep");
    Cat c2;
    c2 = c1;
    c1.setIdea(0, "Hunt");
    std::cout << "c1[0]: " << c1.getIdea(0) << std::endl;
    std::cout << "c2[0]: " << c2.getIdea(0) << std::endl;

    return 0;
}
