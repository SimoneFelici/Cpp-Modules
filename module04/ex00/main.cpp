#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include <cstdlib>

int main()
{
    const Animal* animal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    
    std::cout << dog->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;
    cat->makeSound();
    dog->makeSound();
    animal->makeSound();

    
    delete cat;
    delete dog;
    delete animal;
    
    std::cout << "\n--- Wrong Animal Tests ---\n";
    const WrongAnimal* wrong = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    std::cout << wrongCat->getType() << " " << std::endl;
    wrongCat->makeSound();
    wrong->makeSound();
    
    delete wrongCat;
    delete wrong;
    
    std::cout << "\n--- Array Test ---\n";
    Animal* animals[4];
    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Dog();
    animals[3] = new Cat();
    
    for (int i = 0; i < 4; i++)
        animals[i]->makeSound();
    
    for (int i = 0; i < 4; i++)
        delete animals[i];
    
    return 0;
}
