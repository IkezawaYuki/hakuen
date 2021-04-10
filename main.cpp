#include <iostream>

class Integer
{
    int value;

public:
    Integer(int value) : value{value} {}

    Integer operator+(const Integer& other) const;
    Integer operator-(const Integer& other) const;
    Integer operator*(const Integer& other) const;
    Integer operator/(const Integer& other) const;

    Integer operator+() const;
    Integer operator-() const;

    Integer& operator++();
    Integer& operator--();

    Integer operator++(int);
    Integer operator--(int);

    Integer operator|(const Integer& rhs) const;
    Integer operator&(const Integer& rhs) const;
    Integer operator^(const Integer& rhs) const;

    Integer operator~() const;

    bool operator==(const Integer& rhs) const;
    bool operator!=(const Integer& rhs) const;

    bool operator<(const Integer& rhs) const;
    bool operator>(const Integer& rhs) const;
    bool operator<=(const Integer& rhs) const;
    bool operator>=(const Integer& rhs) const;

    void show() const;
};

bool Integer::operator==(const Integer& rhs) const{
    return value == rhs.value;
}

bool Integer::operator!=(const Integer &rhs) const {
    return !(*this == rhs.value);
}

bool Integer::operator>(const Integer &rhs) const {
    return rhs < *this;
}

bool Integer::operator<=(const Integer &rhs) const {
    return !(rhs < *this);
}

bool Integer::operator>=(const Integer &rhs) const {
    return rhs <= *this;
}


bool Integer::operator<(const Integer &rhs) const {}

Integer Integer::operator+(const Integer &other) const {
    return Integer{value + other.value};
}

Integer Integer::operator-(const Integer &other) const {
    return Integer{value - other.value};
}

Integer Integer::operator*(const Integer &other) const {
    return Integer{value * other.value};
}

Integer Integer::operator/(const Integer &other) const {
    return Integer{value / other.value};
}

Integer Integer::operator+() const {
    return *this;
}

Integer Integer::operator-() const {
    return Integer{-value};
}

Integer Integer::operator|(const Integer &rhs) const {
    return Integer{value | rhs.value};
}

Integer Integer::operator&(const Integer &rhs) const {
    return Integer{value & rhs.value};
}

Integer Integer::operator^(const Integer &rhs) const {
    return Integer{value ^ rhs.value};
}

Integer Integer::operator~() const {
    return Integer{~value};
}

void Integer::show() const
{
    std::cout << "Integer.value = " << value << std::endl;
}

Integer& Integer::operator++() {
    ++value;
    return *this;
}

Integer& Integer::operator--(){
    --value;
    return *this;
}

Integer Integer::operator++(int){
    auto tmp = *this;
    ++*this;
    return tmp;
}

Integer Integer::operator--(int){
    auto tmp = *this;
    --*this;
    return tmp;
}

class Array
{
    int buffer[100];
public:
    int& operator[](int index);
    std::size_t size() const {return 100;}
};

int& Array::operator[](int index) {
    return buffer[index];
}

class int_observer_ptr
{
    int* pointer;
public:
    explicit int_observer_ptr(int* pointer) : pointer{pointer} {}
    int& operator*() const;
};

int& int_observer_ptr::operator*() const {
    return *pointer;
}

class A{
    int value;
public:
    explicit A(int value) : value{value} {}
    void show() const;
};

void A::show() const {
    std::cout << "A.value: " << value << std::endl;
}

class A_observer_ptr
{
    A* pointer;
public:
    explicit A_observer_ptr(A* pointer) : pointer{pointer} {}
    A& operator*() const;
    A* operator->() const;
};

A& A_observer_ptr::operator*() const {
    return *pointer;
}

A* A_observer_ptr::operator->() const {
    return pointer;
}

int main(){
    Integer x = 10;
    Integer y = 3;
    Integer z = 7;

    auto v = x - -y + +z;
    v.show();

    Integer a = 10;
    ++a;

    ++a;
    a.show();

    --a;
    a.show();

    a++;
    a.show();

    a--;
    a.show();

    Array array;
    for (std::size_t i = 0; i < array.size(); ++i) {
        array[i] = i;
    }
    std::cout << array[10] << std::endl;

    A k{42};
    A_observer_ptr pointer{&k};

    (*pointer).show();
    pointer->show();
}