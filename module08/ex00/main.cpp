// main.cpp
#include "easyfind.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <vector>

int main()
{
    // Test vector
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(5);
    vec.push_back(9);

    try {
        int* result = easyfind(vec, 5);
        std::cout << "Found in vector: " << *result << std::endl;
    } catch (std::exception& e) {
        std::cout << "Not found in vector" << std::endl;
    }

    try {
        easyfind(vec, 99);
    } catch (std::exception& e) {
        std::cout << "99 not found (expected)" << std::endl;
    }

    // Test list
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);

    try {
        int* result = easyfind(lst, 20);
        std::cout << "Found in list: " << *result << std::endl;
    } catch (std::exception& e) {
        std::cout << "Not found in list" << std::endl;
    }

    // Test deque
    int arr[] = { 7, 14, 21 };
    std::deque<int> deq(arr, arr + 3);

    try {
        int* result = easyfind(deq, 14);
        std::cout << "Found in deque: " << *result << std::endl;
    } catch (std::exception& e) {
        std::cout << "Not found in deque" << std::endl;
    }

    return 0;
}
