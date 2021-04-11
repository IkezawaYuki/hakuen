#include <iostream>

class Base {
public:
    Base(){
        std::cout << "デフォルトのコンストラクター" << std::endl;
    }

    explicit Base(int i) {
        std::cout << "引数付きのコンストラクター" << i << std::endl;
    }
};

class Derived : public Base{
public:
    explicit Derived(int i) : Base{i} {}
};

int main(){
    Derived derived{42};
}