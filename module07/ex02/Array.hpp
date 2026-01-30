#pragma once

#include <exception>

template <typename T>
class Array {
public:
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    Array& operator=(const Array& other);
    T& operator[](unsigned int n);
    ~Array(void);
    unsigned int size(void) const;

private:
    T* array;
    unsigned int sz;
};

#include "Array.tpp"
