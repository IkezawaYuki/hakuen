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

int main(){
    person alice("alice", 15);
    cout << alice.name() << endl;
}