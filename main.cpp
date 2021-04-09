#include <iostream>
#include <vector>

class A{
    std::string m_name;
    int m_value;

public:
    explicit A(std::string name, int value);
    explicit A(std::string name);
    A();
    void show() const;
};

A::A(std::string name, int value) :m_name(name), m_value(value)
{
}

A::A(std::string name) :A(name, -1)
{
}

A::A(): A("default")
{
}

void A::show() const {
    std::cout << m_name << " " << m_value << std::endl;
}

int main(){
    A a[4] =
            {
            A{"first", 42},
            A{"second"},

            };

    a[0].show();
    a[1].show();
    a[2].show();
    a[3].show();

    std::vector<int> empty;
    std::cout << "empty.size(): " << empty.size() << std::endl;

    std::vector<int> array = {10, 20, 30, 40, 50};
    std::cout << "array.size(): " << array.size() << std::endl;


    for (int i : array) {
        std::cout << i << std::endl;
    }

    array.push_back(42);
    array.push_back(9);
    for (int i : array) {
        std::cout << i << std::endl;
    }

    std::cout  << std::endl;

    array.pop_back();
    for (int i : array) {
        std::cout << i << std::endl;
    }

}