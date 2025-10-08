#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    
    delete i;
    delete j;
    delete meta;
    
    std::cout << "\n--- Wrong Animal Tests ---\n";
    const WrongAnimal* wrong = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    std::cout << wrongCat->getType() << " " << std::endl;
    wrongCat->makeSound();
    wrong->makeSound();
    
    delete static_cast<const WrongCat*>(wrongCat);
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
