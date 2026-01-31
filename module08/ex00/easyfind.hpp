#pragma once

#include <algorithm>
#include <exception>

template <typename T>
int* easyfind(T& a, int b)
{
    typename T::iterator it = std::find(a.begin(), a.end(), b);
    if (it == a.end()) {
        throw std::exception();
    }

    return &(*it);
}
