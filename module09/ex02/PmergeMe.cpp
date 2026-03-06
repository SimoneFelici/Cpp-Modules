#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
    : vecTime(0)
    , deqTime(0)
{
}

PmergeMe::PmergeMe(int argc, char** argv)
    : vecTime(0)
    , deqTime(0)
{
    for (int i = 1; i < argc; ++i) {
        std::istringstream ss(argv[i]);
        int val;
        if (!(ss >> val) || val < 0)
            throw std::invalid_argument("Error: invalid input");
        vec.push_back(val);
        deq.push_back(val);
    }
}

PmergeMe::PmergeMe(const PmergeMe& other)
    : vec(other.vec)
    , vecSorted(other.vecSorted)
    , deq(other.deq)
    , deqSorted(other.deqSorted)
    , vecTime(other.vecTime)
    , deqTime(other.deqTime)
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other) {
        vec = other.vec;
        vecSorted = other.vecSorted;
        deq = other.deq;
        deqSorted = other.deqSorted;
        vecTime = other.vecTime;
        deqTime = other.deqTime;
    }
    return *this;
}

PmergeMe::~PmergeMe() { }

static std::vector<int> jacobsthal(size_t n)
{
    std::vector<int> jac;
    jac.push_back(0);
    jac.push_back(1);
    while ((size_t)jac.back() < n)
        jac.push_back(jac[jac.size() - 1] + 2 * jac[jac.size() - 2]);
    return jac;
}

static std::vector<int> insertionOrder(size_t pend_size)
{
    std::vector<int> order;
    if (pend_size <= 1)
        return order;
    std::vector<int> jac = jacobsthal(pend_size);
    for (size_t k = 2; k < jac.size(); ++k) {
        int hi = std::min((int)pend_size - 1, jac[k] - 1);
        int lo = jac[k - 1];
        for (int idx = hi; idx >= lo; --idx)
            order.push_back(idx);
    }
    return order;
}

std::vector<int> PmergeMe::mergeInsertSort(std::vector<int> v)
{
    size_t n = v.size();
    if (n <= 1)
        return v;

    bool hasStraggler = (n % 2 == 1);
    int straggler = 0;
    if (hasStraggler) {
        straggler = v.back();
        v.pop_back();
        n--;
    }

    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < n; i += 2) {
        int a = v[i], b = v[i + 1];
        if (a < b)
            std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }

    std::vector<int> larger;
    for (size_t i = 0; i < pairs.size(); ++i)
        larger.push_back(pairs[i].first);
    larger = mergeInsertSort(larger);

    std::sort(pairs.begin(), pairs.end());

    std::vector<int> pend;
    for (size_t i = 0; i < pairs.size(); ++i)
        pend.push_back(pairs[i].second);

    std::vector<int> result = larger;
    result.insert(result.begin(), pend[0]);

    std::vector<int> order = insertionOrder(pend.size());
    for (size_t i = 0; i < order.size(); ++i) {
        int idx = order[i];
        int val = pend[idx];
        int partner = pairs[idx].first;

        size_t upper = result.size();
        for (size_t j = 0; j < result.size(); ++j)
            if (result[j] == partner) {
                upper = j + 1;
                break;
            }

        std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.begin() + upper, val);
        result.insert(pos, val);
    }

    if (hasStraggler) {
        std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), straggler);
        result.insert(pos, straggler);
    }
    return result;
}

std::deque<int> PmergeMe::mergeInsertSortDeque(std::deque<int> d)
{
    size_t n = d.size();
    if (n <= 1)
        return d;

    bool hasStraggler = (n % 2 == 1);
    int straggler = 0;
    if (hasStraggler) {
        straggler = d.back();
        d.pop_back();
        n--;
    }

    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < n; i += 2) {
        int a = d[i], b = d[i + 1];
        if (a < b)
            std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }

    std::deque<int> larger;
    for (size_t i = 0; i < pairs.size(); ++i)
        larger.push_back(pairs[i].first);
    larger = mergeInsertSortDeque(larger);

    std::sort(pairs.begin(), pairs.end());

    std::deque<int> pend;
    for (size_t i = 0; i < pairs.size(); ++i)
        pend.push_back(pairs[i].second);

    std::deque<int> result = larger;
    result.push_front(pend[0]);

    std::vector<int> order = insertionOrder(pend.size());
    for (size_t i = 0; i < order.size(); ++i) {
        int idx = order[i];
        int val = pend[idx];
        int partner = pairs[idx].first;

        size_t upper = result.size();
        for (size_t j = 0; j < result.size(); ++j)
            if (result[j] == partner) {
                upper = j + 1;
                break;
            }

        std::deque<int>::iterator pos = std::lower_bound(result.begin(), result.begin() + upper, val);
        result.insert(pos, val);
    }

    if (hasStraggler) {
        std::deque<int>::iterator pos = std::lower_bound(result.begin(), result.end(), straggler);
        result.insert(pos, straggler);
    }
    return result;
}

void PmergeMe::sortVector()
{
    clock_t start = clock();
    vecSorted = mergeInsertSort(vec);
    clock_t end = clock();
    vecTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;
}

void PmergeMe::sortDeque()
{
    clock_t start = clock();
    deqSorted = mergeInsertSortDeque(deq);
    clock_t end = clock();
    deqTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;
}

void PmergeMe::sort()
{
    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << " ";
    std::cout << "\n";

    sortVector();
    sortDeque();

    std::cout << "After:  ";
    for (size_t i = 0; i < vecSorted.size(); ++i)
        std::cout << vecSorted[i] << " ";
    std::cout << "\n";

    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector : " << vecTime << " us\n";
    std::cout << "Time to process a range of " << deq.size()
              << " elements with std::deque  : " << deqTime << " us\n";
}

void PmergeMe::printer()
{
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << " ";
    std::cout << "\n";
    for (size_t i = 0; i < deq.size(); ++i)
        std::cout << deq[i] << " ";
    std::cout << "\n";
}
