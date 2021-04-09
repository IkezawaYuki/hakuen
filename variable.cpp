//
// Created by 池澤勇輝 on 2021/04/08.
//

#include <iostream>

int value = 42;

void show_extern_variable(){
    std::cout << "extern変数のアドレス" << &value << std::endl;
    std::cout << "extern変数の値" << value << std::endl;
}