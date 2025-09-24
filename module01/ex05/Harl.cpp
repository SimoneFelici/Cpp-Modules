#include "Harl.hpp"
#include <iostream>

void Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    typedef void (Harl::*MemFn)();
    const char* names[] = {
        "DEBUG", "INFO", "WARNING", "ERROR"
    };
    const MemFn funcs[] = {
        &Harl::debug, &Harl::info, &Harl::warning, &Harl::error
    };

    for (size_t i = 0; i < sizeof(names)/sizeof(names[0]); ++i)
    {
        if (level == names[i])
        {
            (this->*funcs[i])();
            return;
        }
    }
    std::cout << "Where am I?" << std::endl;
}
