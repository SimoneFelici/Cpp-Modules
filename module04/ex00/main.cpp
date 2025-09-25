#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

static void hr(const std::string& title)
{
    std::cout << "\n===== " << title << " =====\n";
}

static void speak(const Animal& a)
{
    a.makeSound();
}

int main()
{
    // 1) Costruzione base e polimorfismo via puntatori a base
    hr("Base creation & polymorphism");
    const Animal* base = new Animal();
    const Animal* pdog = new Dog();
    const Animal* pcat = new Cat();

    std::cout << "Types: " << pdog->getType() << ", " << pcat->getType() << std::endl;
    pdog->makeSound();           // Dog
    pcat->makeSound();           // Cat
    base->makeSound();           // Animal

    // 2) Distruzione tramite puntatore a base (verifica distruttore virtuale)
    hr("Delete via base*");
    delete pcat;
    delete pdog;
    delete base;

    // 3) Costruzione su stack + copy constructor / copy assignment
    hr("Copy ctor / copy assignment");
    Dog d1;            // default
    Dog d2(d1);        // copy ctor
    Dog d3; d3 = d1;   // copy assignment
    d1.makeSound();
    d2.makeSound();
    d3.makeSound();

    Cat c1;
    Cat c2(c1);
    Cat c3; c3 = c1;
    c1.makeSound();
    c2.makeSound();
    c3.makeSound();

    // 4) Self-assignment (non deve rompere nulla)
    hr("Self-assignment");
    d1 = d1;
    c1 = c1;

    // 5) Dispatch tramite reference const (test cost-correctness)
    hr("Dispatch through const Animal&");
    speak(Dog());
    speak(Cat());

    // 6) Array polimorfico e cleanup
    hr("Polymorphic array and cleanup");
    const size_t N = 6;
    Animal* zoo[N];
    for (size_t i = 0; i < N; ++i)
        zoo[i] = (i % 2 == 0) ? static_cast<Animal*>(new Dog()) : static_cast<Animal*>(new Cat());
    for (size_t i = 0; i < N; ++i)
        zoo[i]->makeSound();
    for (size_t i = 0; i < N; ++i)
        delete zoo[i];

    // 7) Slicing dimostrativo: il tipo "dinamico" va perso
    hr("Object slicing demo");
    Dog d4;
    Animal a = d4;    // slicing: rimane solo la parte Animal
    std::cout << "Sliced Animal type: " << a.getType() << std::endl;
    a.makeSound();    // chiama Animal::makeSound(), non Dog::makeSound()

    // 8) Puntatore a base const (ulteriore test di metodi const)
    hr("Const base* usage");
    const Animal* cp = new Dog();
    std::cout << "Const base* getType(): " << cp->getType() << std::endl;
    cp->makeSound();  // deve compilare solo se makeSound() è const nelle derivate
    delete cp;

    hr("Done");
    return 0;
}
