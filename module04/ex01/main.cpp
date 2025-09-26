#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Single alloc/free test ===\n";
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j; // should not leak
    delete i;

    std::cout << "\n=== Polymorphic array test ===\n";
    const int N = 10;
    Animal* zoo[N];

    for (int idx = 0; idx < N; ++idx)
    {
        if (idx < N/2) zoo[idx] = new Dog();
        else           zoo[idx] = new Cat();
    }

    for (int idx = 0; idx < N; ++idx)
        delete zoo[idx];

    std::cout << "\n=== Deep copy tests (Dog) ===\n";
    Dog a;
    a.setIdea(0, "Chase ball");
    Dog b(a);
    std::cout << "a[0]=" << a.getIdea(0) << " | b[0]=" << b.getIdea(0) << "\n";
    a.setIdea(0, "Chew bone");
    std::cout << "after change: a[0]=" << a.getIdea(0) 
              << " | b[0]=" << b.getIdea(0) << " (b unchanged)\n";

    std::cout << "\n=== Deep copy tests (Cat, assignment) ===\n";
    Cat c1;
    c1.setIdea(1, "Nap on keyboard");
    Cat c2;
    c2 = c1;
    std::cout << "c1[1]=" << c1.getIdea(1) << " | c2[1]=" << c2.getIdea(1) << "\n";
    c1.setIdea(1, "Knock glass off table");
    std::cout << "after change: c1[1]=" << c1.getIdea(1)
              << " | c2[1]=" << c2.getIdea(1) << " (c2 unchanged)\n";

    std::cout << "\n=== Sounds ===\n";
    const Animal* d = new Dog();
    const Animal* c = new Cat();
    d->makeSound();
    c->makeSound();
    delete d;
    delete c;

    return 0;
}
