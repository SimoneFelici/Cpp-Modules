#include "Contact.hpp"

int Contact::get_index() const
{
    return index;
}
std::string Contact::get_first() const
{
    return first_name;
}
std::string Contact::get_last() const
{
    return last_name;
}
std::string Contact::get_nick() const
{
    return nickname;
}
std::string Contact::get_secret() const
{
    return secret;
}
std::string Contact::get_num() const
{
    return tel_num;
}

void Contact::set_index(int n)
{
    index = n;
}
void Contact::set_first(const std::string& s)
{
    first_name = s;
}
void Contact::set_last(const std::string& s)
{
    last_name = s;
}
void Contact::set_nick(const std::string& s)
{
    nickname = s;
}
void Contact::set_secret(const std::string& s)
{
    secret = s;
}
void Contact::set_num(const std::string& n)
{
    tel_num = n;
}
