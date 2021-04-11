#include <iostream>

class BaseA{
    int value;
public:
    explicit BaseA(int value) : value{value} {}
    void show_BaseA()
    {
        std::cout << "BaseA.value" << value << std::endl;
    }
};

class BaseB{
    int values;
public:
    explicit BaseB(int values): values{values} {}
    void show_BaseB()
    {
        std::cout << "BaseB.value = " << values << std::endl;
    }
};

class Derived : public BaseA, public BaseB
{
public:
    Derived(int a, int b);
};

Derived::Derived(int a, int b) :BaseA{a}, BaseB{b} {

}

class Base
{
    int value;
public:
    Base(int value) : value{value}{}
    void show();
};

void Base::show() {
    std::cout << "this: " << this << std::endl
    << "this->value: " << value << std::endl;
}

class DerivedA : public Base{
public:
    DerivedA(int value) : Base{value} { }
};

class DerivedB : public Base{
public:
    DerivedB(int value) : Base{value} { }
};

class MoreDerived: public DerivedA, public DerivedB {
public:
    MoreDerived(int d_a, int d_b) : DerivedA{d_a}, DerivedB{d_b}
    {

    }
};

int main(){
    MoreDerived more_derived{42, 72};
    more_derived.DerivedA::show();
    more_derived.DerivedB::show();
}