#pragma once
#include <algorithm>
#include <ctime>
#include <deque>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(int argc, char** argv);
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();
    void sort();
    void printer();

private:
    std::vector<int> vec;
    std::vector<int> vecSorted;

    std::deque<int> deq;
    std::deque<int> deqSorted;

    double vecTime;
    double deqTime;

    std::vector<int> mergeInsertSort(std::vector<int> v);
    std::deque<int> mergeInsertSortDeque(std::deque<int> d);

    void sortVector();
    void sortDeque();
};
