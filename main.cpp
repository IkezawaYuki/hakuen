#include <iostream>
#include <string>

using namespace std;

class person {
    std::string m_name;
    int m_age;
    person(int age);
public:
    person();
    person(std::string name, int age);
    ~person();
    person(const person& other);

    void set_name(std::string name);
    void set_age(int age);

    std::string name() const;
    int age() const;
};

person::person(int age) : m_age(age) {
    cout << "共通のコンストラクター呼びだし" << endl;
}

person::person() :person(-1) {
    cout << "引数なしコンストラクター呼び出し" << endl;
}

person::person(std::string name, int age) : person(age) {
    cout << "引数付きコンストラクタの呼び出し" << endl;
    set_name(name);
}

person::person(const person& other) {
    cout << "コピーコンストラクター呼び出し" << endl;
    set_name(other.name());
    set_age(other.age());
}

person::~person() {
    cout << "デストラクター呼び出し" << endl;
}

void person::set_name(std::string name) {
    m_name = name;
}

void person::set_age(int age) {
    m_age = age;
}

std::string person::name() const {
    return m_name;
}

int person::age() const{
    return m_age;
}

class A {
    int m_v;
public:
    A(int);
    int v() const;
};

A::A(int v) : m_v(v) {

}

int A::v() const {
    return m_v;
}

int main(){
    person alice("alice", 15);
    person copy(alice);
    cout << alice.name() << endl;
    cout << copy.name() << endl;

    A x = 42;
    if (x.v() == 42) {
        cout << "A.v()は42です" << endl;
    } else {
        cout << "A.v()は42ではありません" << endl;
    }
}

class Book {
    string title;
    string writer;
    int price;

public:
    Book(string title, string writer, int price);
    Book(const Book& other);
};

Book::Book(string t, string w, int p) {
    title = t;
    writer = w;
    price = p;
}

Book::Book(const Book& other) {
    title = other.title;
    writer = other.writer;
    price = other.price;
}
