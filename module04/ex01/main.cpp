#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    std::cout << "\n--- Animals ---\n";

    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i;

    std::cout << "\n--- Deep copy test ---\n";
    Dog dog1;
    dog1.setIdea(0, "Chase ball");

    Dog dog2(dog1);
    dog1.setIdea(0, "Chew bone");

    std::cout << "dog1[0]: " << dog1.getIdea(0) << std::endl;
    std::cout << "dog2[0]: " << dog2.getIdea(0) << std::endl;

    Cat c1;
    c1.setIdea(0, "Sleep");
    Cat c2;
    c2 = c1;
    c1.setIdea(0, "Hunt");
    std::cout << "c1[0]: " << c1.getIdea(0) << std::endl;
    std::cout << "c2[0]: " << c2.getIdea(0) << std::endl;
}
