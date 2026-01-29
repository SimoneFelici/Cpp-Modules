#pragma once

#include <stdint.h>
#include <string>

typedef struct Data {
    std::string name;
    int age;
    float height;

} Data;

class Serializer {
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);

private:
    Serializer();
    ~Serializer();
    Serializer(const Serializer& other);
    Serializer& operator=(const Serializer& other);
};
