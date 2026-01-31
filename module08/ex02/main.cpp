#include "Array.hpp"
#include <iostream>

int main()
{
    Array<int> a(9);
    int mhhh = 0;

    for (unsigned int i = 0; i < a.size(); i++) {
        a[i] = mhhh++;
    }

    for (unsigned int j = 0; j < a.size(); j++) {
        std::cout << a[j] << std::endl;
    }

    a[20] = 1;
}
