#include <iostream>
#include <string>

using namespace std;

class person {
    std::string m_name;
    int m_age;

public:
    person();
    void set_name(std::string name);
    void set_age(int age);

    std::string name() const;
    int age() const;
};

person::person():m_age(-1) {
    cout << "コンストラクター呼び出し" << endl;
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

int person::age() const {
    return m_age;
}

int main(){
    person bob;
    cout << "初期化直後の年齢: " << bob.age() << endl;
    bob.set_name("bob");
    bob.set_age(20);
    cout << "名前:" << bob.name() << endl;
    cout << "年齢:" << bob.age() << endl;
}