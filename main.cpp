#include <iostream>

using namespace std;

class Shape {
public:
    virtual float area() const = 0;
    virtual float perimeter() const = 0;
};

class Rectangle : public Shape {
    float height;
    float width;

public:
    explicit Rectangle(float height, float width);
    float area() const override;
    float perimeter() const override;
};

Rectangle::Rectangle(float height, float width): height(height), width(width){

}

float Rectangle::area() const {
    return height * width;
}

float Rectangle::perimeter() const {
    return 2 * (height + width);
}

class Circle : public Shape {
    float r;
public:
    explicit Circle(float r);
    float area() const override;
    float perimeter() const override;
};

Circle::Circle(float r) : r(r) {

}

float Circle::area() const {
    return r * r * 3.14f;
}

float Circle::perimeter() const {
    return 2 * r * 3.14f;
}

class Base {
public:
    virtual string name() const;
};

string Base::name() const{
    return "Base";
}

class Derived : public Base {
public:
    string name() const override;
};

string Derived::name() const {
    return "Derived";
}

class A {
public:
    void foo();
};

void A::foo() {
    cout << "A::foo()" << endl;
}

void call_foo(A* pa) {
    pa -> foo();
}

class B {
    int value;
public:
    void set_value(int value);
    int get_value() const;
};

void B::set_value(int value) {
    this->value = value;
}

int B::get_value() const {
    return value;
}

int main(){
    A a;
    call_foo(&a);

    B b;
    b.set_value(42);
    cout << b.get_value() << endl;
}