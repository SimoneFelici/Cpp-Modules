#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include "PhoneBook.hpp"

bool is_num(const std::string& s)
{
    for (std::string::size_type i = 0; i < s.size(); ++i)
    {
        unsigned char ch = static_cast<unsigned char>(s[i]);
        if (!std::isdigit(ch))
            return false;
    }
    return !s.empty();
}

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
    std::string first;
    std::string last;
    std::string nick;

    while (true)
    {
        std::cout << "> "; 
        if (!std::getline(std::cin, cmd))
        {
            std::cout << "bye :)" << std::endl;
            return 0;
        }
        if (cmd == "ADD")
        {
            do {
                std::cout << "> Enter the first name (required): ";
                if (!std::getline(std::cin, first))
                {
                    std::cout << "bye :)" << std::endl;
                    return 0;
                }
                if (first.empty())
                    std::cout << "  First name cannot be empty." << std::endl;
            } while (first.empty());
            book.contact[i].set_first(first);

            std::cout << "> Enter the last name (optional): ";
            if (!std::getline(std::cin, last)) {
                std::cout << "bye :)" << std::endl;
                return 0;
            }
            book.contact[i].set_last(last);
            std::cout << "> Enter the nickname (optional): ";
            if (!std::getline(std::cin, nick)) {
                std::cout << "bye :)" << std::endl;
                return 0;
            }
            book.contact[i].set_nick(nick);

            do {
                std::cout << "> Enter the phone number (required): ";
                if (!std::getline(std::cin, num)) {
                    std::cout << "bye :)" << std::endl;
                    return 0;
                }
                if (num.empty())
                    std::cout << "  Phone number cannot be empty." << std::endl;
                else if (!is_num(num))
                    std::cout << "  Only numbers allowed." << std::endl;
            } while (num.empty() || !is_num(num));
            book.contact[i].set_num(num);

            std::cout << "> Enter the darkest secret (optional): ";
            if (!std::getline(std::cin, sec)) {
                std::cout << "bye :)" << std::endl;
                return 0;
            }
            book.contact[i].set_secret(sec);

            book.contact[i].set_index(i);
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
                    std::cout << "| " << std::setw(10) << book.contact[j].get_index() << " | " << std::setw(10) << tr10(book.contact[j].get_first()) << " | " << std::setw(10) << tr10(book.contact[j].get_last()) << " | " << std::setw(10) << tr10(book.contact[j].get_nick()) << " |" << std::endl;
                    j++;
                }
                std::cout << "> Enter the index: ";
                std::string idx_line;
                if (!std::getline(std::cin, idx_line))
                {
                    std::cout << "bye :)\n";
                    return 0;
                }
                if (!is_num(idx_line))
                {
                    std::cout << "  Not a number :)\n";
                    continue;
                }
                int index = std::stoi(idx_line);

                if (index >= 0 && index < count)
                {
                    std::cout << "Index: " << book.contact[index].get_index() << std::endl;
                    std::cout << "First Name: " << book.contact[index].get_first() << std::endl;
                    std::cout << "Last Name: " << book.contact[index].get_last() << std::endl;
                    std::cout << "Nickname: " << book.contact[index].get_nick() << std::endl;
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
