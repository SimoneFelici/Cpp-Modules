#include <iostream>
#include <string>
#include <fstream>

void replace(size_t pos, std::string &row, const std::string &s1, const std::string &s2)
{
    row = row.substr(0, pos) + s2 + row.substr(pos + s1.size());
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Wrong number of args.\nUsage: " << argv[0] << " filename s1 s2" << std::endl;
        return 1;
    }

    const std::string out = argv[1];
    const std::string s1  = argv[2];
    const std::string s2  = argv[3];

    if (s1.empty())
    {
        std::cerr << "s1 must not be empty" << std::endl;
        return 1;
    }

    std::ifstream infile(argv[1]);
    if (!infile)
    {
        std::cerr << "Cant open " << argv[1] << std::endl;
        return 1;
    }

    std::ofstream outfile((out + ".replace").c_str());
    if (!outfile)
    {
        std::cerr << "Cant create " << (out + ".replace") << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(infile, line))
    {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            replace(pos, line, s1, s2);
            pos += s2.size();
        }
        outfile << line << std::endl;
    }

    return 0;
}
