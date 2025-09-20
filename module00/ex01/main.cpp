#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include "PhoneBook.hpp"

std::string tr10(std::string s)
{
    if (s.size() > 10)
        return s.substr(0, 9) + ".";
    return s;
}

int main()
{
    std::string cmd;
    PhoneBook book;
    int i = 0;
    int j = 0;
    int index = 0;
    int count = 0;
    std::string num;
    std::string sec;

    while (true)
    {
        std::cout << "> "; 
        std::getline(std::cin, cmd);

        if (cmd == "ADD")
        {
            do {
                std::cout << "> Enter the first name (required): ";
                std::getline(std::cin, book.contact[i].first_name);
                if (book.contact[i].first_name.empty())
                    std::cout << "  First name cannot be empty." << std::endl;
            } while (book.contact[i].first_name.empty());

            std::cout << "> Enter the last name (optional): ";
            std::getline(std::cin, book.contact[i].last_name);

            std::cout << "> Enter the nickname (optional): ";
            std::getline(std::cin, book.contact[i].nickname);

            do {
                std::cout << "> Enter the phone number (required): ";
                std::getline(std::cin, num);
                if (num.empty())
                    std::cout << "  Phone number cannot be empty." << std::endl;
            } while (num.empty());
            book.contact[i].set_num(num);

            std::cout << "> Enter the darkest secret (optional): ";
            std::getline(std::cin, sec);
            book.contact[i].set_secret(sec);

            book.contact[i].index = i;
            i = (i+1) % 8;
            if (count < 8)
                ++count;
        }
        else if (cmd =="SEARCH")
        {
            j = 0;
            if (count > 0)
            {
                std::cout << " ---------------------------------------------------" << std::endl;
                std::cout << "| " << std::setw(10) << "Index" << " | " << std::setw(10) << "First Name" << " | " << std::setw(10) << "Last Name" << " | " << std::setw(10) << "Nickname" << " |" << std::endl;
                while(j < count)
                {
                    std::cout << " ---------------------------------------------------" << std::endl;
                    std::cout << "| " << std::setw(10) << book.contact[j].index << " | " << std::setw(10) << tr10(book.contact[j].first_name) << " | " << std::setw(10) << tr10(book.contact[j].last_name) << " | " << std::setw(10) << tr10(book.contact[j].nickname) << " |" << std::endl;
                    j++;
                }
                std::cout << "> Enter the index: ";
                if (!(std::cin >> index))
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "  Not a number :)" << std::endl;
                    continue;
                }
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                if (index >= 0 && index < count)
                {
                    std::cout << "Index: " << book.contact[index].index << std::endl;
                    std::cout << "First Name: " << book.contact[index].first_name << std::endl;
                    std::cout << "Last Name: " << book.contact[index].last_name << std::endl;
                    std::cout << "Nickname: " << book.contact[index].nickname << std::endl;
                    std::cout << "Phone Number: " << book.contact[index].get_num() << std::endl;
                    std::cout << "Darkest Secret: " << book.contact[index].get_secret() << std::endl;
                }
                else
                {
                    std::cout << "  Invalid Index" << std::endl;
                }
            }
            else
                std::cout << "  No contact saved (not surprising)" << std::endl;
        }
        else if (cmd == "EXIT")
        {
            std::cout << "bye :)" << std::endl;
            return (0);
        }
        else
            std::cout << "  " << cmd << " was not recognized💀" << std::endl;
    }
}
