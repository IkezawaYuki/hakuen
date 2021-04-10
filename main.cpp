#include <iostream>
#include <initializer_list>

class Triangle
{
    float height;
    float width;

public:
    explicit Triangle(float height, float width);
    float area() const;
};

Triangle::Triangle(float height, float width) :height(height), width(width)
{
}

float Triangle::area() const {
    return height * width / 2;
}

class Object{
    std::string name;
public:
    Object():Object("No Name"){}
    explicit Object(std::string name) : name(name){}
    ~Object();
    void show_name() const;
};

Object::~Object()
{
    std::cout << "Objectのデストラクター" << std::endl;
}

void Object::show_name()const {
    std::cout << "object name: " << name << std::endl;
}

class A {
    int m_v;
    std::string m_n;
public:
    A(int, std::string);
    A(float );
};

A::A(int v, std::string n):m_v(v), m_n{n}
{
}

A::A(float) : A{-1, "float"}
{
}

class int_vector
{
    std::size_t m_size;
    int* m_array;

public:
    int_vector(std::initializer_list<int> init);
    ~int_vector();
    std::size_t size() const
    {
        return m_size;
    }
    int at(int n) const
    {
        return m_array[n];
    }
};

int_vector::int_vector(std::initializer_list<int> init)
    :m_size{init.size()}, m_array{new int [init.size()]}
{
    for (std::size_t i = 0; i < init.size(); ++i)
    {
        m_array[i] = init[i];
    }
}

int_vector::~int_vector()
{
    delete [] m_array;
}

int main() {
    Triangle* tri = new Triangle{10.0f, 5.0f};
    std::cout << "三角形の面積:" << tri->area() << std::endl;
    delete tri;

    Object* obj = new Object[10]
    {
        Object{"first"},
        Object{"second"},
    };

    obj[0].show_name();
    obj[1].show_name();
    obj[2].show_name();

    delete [] obj;

    A ap(42, "0");
    A ab{42, "0"};
    A bp = A(42, "0");
    A bb = A{42, "0"};
    A cb = {42,"0"};
    A db = (42, 0.0);

    int_vector iv = {0, 1, 2, 3, 4, 5};
    std::cout << "iv.size() = " << iv.size() << std::endl;
    std::cout << "iv.at(3) = " << iv.at(3) << std::endl;

}