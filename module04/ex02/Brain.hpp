#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain
{
    public:
        Brain();
        Brain(const Brain& other);
        Brain &operator=(const Brain& other);
        ~Brain();

        void setIdea(int idx, const std::string& idea);
        const std::string& getIdea(int idx) const;
    private:
        std::string ideas[100];
};

#endif
