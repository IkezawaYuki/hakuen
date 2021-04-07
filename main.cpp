#include <iostream>
using namespace std;

class A{
    union {
        int i;
        float f;
    };
    long l;
public:
    A();
    int get_i() const;
    void set_f(float f);
    long get_l() const;
};

A::A() : i(0xdeadbeef), l(0xc0ffee) {
    cout << "&f: " << &f << endl
         << "&i: " << &i << endl
         << "&l: " << &l << endl;
}

int A::get_i() const {
    return i;
}

void A::set_f(float f) {
    this->f = f;
}

long A::get_l() const {
    return l;
}

int main(){
    A a;
    cout << "i: " << hex << a.get_i() << endl;
}