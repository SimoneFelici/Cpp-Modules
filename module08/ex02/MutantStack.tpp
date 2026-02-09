#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(void)
    : std::stack<T>()
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other)
    : std::stack<T>(other)
{
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other)
{
    *this = other;
    return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack(void)
{
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{
    return (std::stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin(void) const
{
    return (std::stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
    return (std::stack<T>::c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end(void) const
{
    return (std::stack<T>::c.end());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin(void)
{
    return (std::stack<T>::c.rbegin());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin(void) const
{
    return (std::stack<T>::c.rbegin());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend(void)
{
    return (std::stack<T>::c.rend());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend(void) const
{
    return (std::stack<T>::c.rend());
}
