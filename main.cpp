#include <iostream>

using namespace std;

class Base {
public:
    void foo();
};

void Base::foo(){
    cout << "Base::foo()" << endl;
}

class Derived : public Base {
public:
    using Base::foo;
    void foo(int v);
};

void Derived::foo(int v) {
    cout << "Derived::foo(" << v << ")" << endl;
}

int main(){
    Derived derived;
    derived.foo();
    derived.foo(42);
}