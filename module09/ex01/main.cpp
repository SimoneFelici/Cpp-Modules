#include "RPN.hpp"
#include <algorithm>
#include <iostream>
#include <string>

void operation()
{
}

int main(int argc, char** argv)
{

    if (argc != 2) {
        std::cerr << "Error\n";
        return (1);
    }
    std::string line = argv[1];
    line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
    // std::cout << line << '\n';

    RPN rpn(line);

    int res = rpn.eval();

    std::cout << res << std::endl;
}
