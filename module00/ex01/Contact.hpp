#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
public:
    int get_index() const;
    std::string get_first() const;
    std::string get_last() const;
    std::string get_nick() const;
    std::string get_secret() const;
    std::string get_num() const;

    void set_index(int n);
    void set_first(const std::string& s);
    void set_last(const std::string& s);
    void set_nick(const std::string& s);
    void set_secret(const std::string& s);
    void set_num(const std::string& n);

private:
    int index;
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string secret;
    std::string tel_num;
};

#endif
