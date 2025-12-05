#include "Bureaucrat.hpp"
#include <iostream>
#include <typeinfo>

int main()
{
    Bureaucrat fire("Marius", 4);

    std::cout << fire;
    try
    {
        fire.incrementGrade();
        std::cout << fire;
        fire.incrementGrade();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << "Type: " << typeid(e).name() << std::endl;
    }
}
