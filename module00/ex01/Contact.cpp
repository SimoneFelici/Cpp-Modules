#include "Contact.hpp"

int Contact::get_index() { return index; }
std::string Contact::get_first() { return first_name; }
std::string Contact::get_last() { return last_name; }
std::string Contact::get_nick() { return nickname; }
std::string Contact::get_secret() { return secret; }
std::string Contact::get_num() { return tel_num; }

void Contact::set_index(int n) { index = n; }
void Contact::set_first(const std::string& s) { first_name = s; }
void Contact::set_last(const std::string& s) { last_name = s; }
void Contact::set_nick(const std::string& s) { nickname = s; }
void Contact::set_secret(const std::string& s) { secret = s; }
void Contact::set_num(const std::string& n) { tel_num = n; }
