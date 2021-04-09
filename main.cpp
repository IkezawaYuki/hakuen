#include <iostream>

int main(){
    int array[] = {0,1,2,3};
    std::cout << "先頭のアドレス：" << &array[0] << std::endl;

    int* ptr = array;
    std::cout << "ポインター：" << ptr << std::endl;
    std::cout << "値：" << *ptr << std::endl;

    std::cout << ptr[0] << std::endl;
    std::cout << ptr[1] << std::endl;
    std::cout << ptr[2] << std::endl;
    std::cout << ptr[3] << std::endl;

    ptr += 2;
    std::cout << *ptr << std::endl;

    ++ptr;
    std::cout << *ptr << std::endl;

    ptr -= 2;
    std::cout << *ptr << std::endl;

    --ptr;
    std::cout << *ptr << std::endl;

    for (int e : array){
        std::cout << e << std::endl;
    }

    int (*pointer)[4] = &array;

    for (int e : *pointer) {
        std::cout << e << std::endl;
    }

    int (&ref)[4] = array;
    for (int e : ref) {
        std::cout << e << std::endl;
    }
}