#include "PmergeMe.hpp"

#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
    if (argc < 2) {
        std::cerr << "Error: no input\n";
        return 1;
    }
    try {
        PmergeMe pm(argc, argv);
        pm.sort();
    } catch (std::exception& e) {
        std::cerr << e.what() << "\n";
        return 1;
    }
    return 0;
}
