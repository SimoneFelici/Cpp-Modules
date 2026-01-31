#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
    array = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n)
    : sz(n)
{
    this->array = new T[this->sz];
}

template <typename T>
Array<T>::Array(const Array& other)
    : sz(other.sz)
{
    if (sz > 0) {
        this->array = new T[this->sz];
        for (unsigned int i = 0; i < this->sz; i++) {
            this->array[i] = other.array[i];
        }
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this == &other)
        return (*this);
    if (this->array)
        delete[] this->array;

    this->sz = other.sz;
    if (this->sz > 0) {
        this->array = new T[this->sz];
        for (unsigned int i = 0; i < this->sz; i++) {
            this->array[i] = other->array[i];
        }
    } else
        array = new T[0];
    return (*this);
}

template <typename T>
T& Array<T>::operator[](unsigned int n)
{
    if (n >= sz)
        throw std::exception();
    return (this->array[n]);
}

template <typename T>
unsigned int Array<T>::size(void) const
{
    return (this->sz);
}

template <typename T>
Array<T>::~Array(void)
{
    delete[] array;
}
