#include <iostream>

int* local()
{
    int i = 42;
    return &i;
}

int* dyn_alloc()
{
    int* ptr = new int;
    *ptr = 42;
    return ptr;
}

int main()
{
    int* d = dyn_alloc();
    std::cout << *d << std::endl;
    delete d;
}