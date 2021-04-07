#include <iostream>

class Base{
    int value = 0;

public:
    void set_value(int value);
    int get_value()const;
};

void Base::set_value(int value) {
    this->value = value;
}

int Base::get_value() const {
    return value;
}

struct Derived: Base{
    Derived();
    ~Derived();
};

Derived::Derived() {
    std::cout << "コンストラクター" << std::endl;
}

Derived::~Derived() {
    std::cout << "デストラクター" << std::endl;
}

union U {
    float f;
private:
    int i;
public:
    U();
    int get_i() const;
};

U::U() : i(0xdeadbeef) {
    std::cout << "&f: " << &f << std::endl
    << "&i: " << &i << std::endl;
}

int U::get_i() const {
    return this->i;
}

int main(){
    Derived d;
    std::cout << d.get_value() << std::endl;
    d.set_value(42);
    std::cout << d.get_value() << std::endl;

    U u;
    std::cout << std::hex << u.get_i() << std::endl;
    u.f = 2.71828f;
    std::cout << std::hex << u.get_i() << std::endl;
}