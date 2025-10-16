#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include <cstdlib>

int main()
{
    std::cout << "\n--- Animals ---\n";
    const Animal* animal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    
    std::cout << "\n--- Types ---\n";
    std::cout << dog->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;
    std::cout << animal->getType() << " " << std::endl;
    
    std::cout << "\n--- Sounds ---\n";
    cat->makeSound();
    dog->makeSound();
    animal->makeSound();

    
    delete cat;
    delete dog;
    delete animal;
    
    std::cout << "\n--- Wrong Animals ---\n";
    const WrongAnimal* wronganimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << "\n--- Types ---\n";
    std::cout << wrongCat->getType() << " " << std::endl;
    std::cout << wronganimal->getType() << " " << std::endl;

    std::cout << "\n--- Sounds ---\n";
    wrongCat->makeSound();
    wronganimal->makeSound();
    
    delete wrongCat;
    delete wronganimal;
}
