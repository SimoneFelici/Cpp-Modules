#include <string>

class Contact {
    public:
        int index;
        std::string first_name;
        std::string last_name;
        std::string nickname;

        void set_secret(std::string s)
        {
            secret = s;
        };
        std::string get_secret()
        {
            return secret;
        }
        void set_num(std::string n)
        {
            tel_num = n;
        };
        std::string get_num()
        {
            return tel_num;
        }
    private:
        std::string secret;
        std::string tel_num;
};

