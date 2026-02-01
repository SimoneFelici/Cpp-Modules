// main.cpp
#include "easyfind.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <vector>

int main()
{
    std::vector<int> vec;
    std::vector<int>::iterator it_vec;
    vec.push_back(1);
    vec.push_back(5);
    vec.push_back(9);

    try {
        it_vec = easyfind(vec, 5);
        std::cout << "Found in vector: " << *it_vec << std::endl;
    } catch (std::exception& e) {
        std::cout << "Not found in vector" << std::endl;
    }

    try {
        easyfind(vec, 99);
    } catch (std::exception& e) {
        std::cout << "99 not found (expected)" << std::endl;
    }

    std::list<int> lst;
    std::list<int>::iterator it_lst;
    lst.push_back(10);
    lst.push_back(20);

    try {
        it_lst = easyfind(lst, 20);
        std::cout << "Found in list: " << *it_lst << std::endl;
    } catch (std::exception& e) {
        std::cout << "Not found in list" << std::endl;
    }

    int arr[] = { 7, 14, 21 };
    std::deque<int> deq(arr, arr + 3);
    std::deque<int>::iterator it_deq;

    try {
        it_deq = easyfind(deq, 14);
        std::cout << "Found in deque: " << *it_deq << std::endl;
    } catch (std::exception& e) {
        std::cout << "Not found in deque" << std::endl;
    }
}
