#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data me;
    uintptr_t raw;
    Data* ptr;

    me.name = "Simone";
    me.age = 23;
    me.height = 1.75f;
    std::cout << "Original Pointer: " << &me << std::endl;

    raw = Serializer::serialize(&me);
    std::cout << "Serialized Pointer: " << &raw << std::endl;

    ptr = Serializer::deserialize(raw);
    std::cout << "Deserialized Pointer: " << ptr << std::endl;

    if (ptr == &me) {
        std::cout << "Equals" << std::endl;
    } else {
        std::cout << "Not equals" << std::endl;
    }
}
