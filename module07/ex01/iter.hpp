template <typename T>
void iter(T* array, unsigned int len, void (*f)(T&))
{
    for (unsigned int i = 0; i < len; i++)
        f(array[i]);
}

template <typename T>
void iter(T const* array, unsigned int len, void (*f)(T const&))
{
    for (unsigned int i = 0; i < len; i++)
        f(array[i]);
}
