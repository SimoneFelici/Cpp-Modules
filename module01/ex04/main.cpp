#include <iostream>
#include <string>
#include <fstream> 

void replace(size_t pos, std::string &row, std::string s1, std::string s2)
{
    row = row.substr(0, pos) + s2 + row.substr(pos + s1.size(), row.size());
}

int main(int argc, char **argv)
{
    std::string input;
    size_t i = 0;

    if (argc == 4)
    {
        const std::string out = argv[1];
        std::ifstream infile(argv[1]);
        if (!infile)
        {
            std::cerr << "Cant open " << argv[1] << std::endl;
            return 1;
        }
        std::ofstream outfile(out + ".replace");
        if (!outfile)
        {
            std::cerr << "Cant create " << out << std::endl; return 1;
        }
        while (std::getline (infile, input))
        {
            i = input.find(argv[2], 0);
            if (i != std::string::npos)
                replace(i, input, argv[2], argv[3]);
            outfile << input << std::endl;
        }
        infile.close();
        outfile.close();
    }
    else
    {
        std::cout << "Wrong number of args." << std::endl << "Usage: " << argv[0] << " filename s1 s2" << std::endl;
    }
}
