#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char** argv)
{
    (void)argv;
    if (argc != 2) {
        std::cerr << "ERROR: Invalid arguments\n";
        return (1);
    }

    BitcoinExchange db;

    try {
        db.loadDB();
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << "\n";
        return (1);
    }

    db.printMap();

    double a = 39141.25;
    std::cout << a << '\n';
}
