#include <iostream>

class Marker
{
public:
    Marker();
    ~Marker();
};

Marker::Marker()
{
    std::cout << "コンストラクター" << this << std::endl;
}

Marker::~Marker()
{
    std::cout << "デストラクター" << this << std::endl;
}

void copy(Marker m)
{
    std::cout << "copy: " << &m << std::endl;
}

void reference(const Marker& m) {
    std::cout << "reference: " << &m << std::endl;
}

class Object
{
    std::string name;
public:
    Object(std::string name);
    const std::string& get_name()const;
};

Object::Object(std::string name) :name{name}
{
    //
}

const std::string & Object::get_name() const {
    return name;
}

int& id(int& i) {
    return i;
}

class person
{
    std::string m_name;
    int m_age;
    person(int age) : m_age {age} {};

public:
    person() : person{-1} {}
    person(std::string name, int age) : m_name{name}, m_age{age} {}

    person(person&& other);
    const std::string& name() const{return m_name;}
    int age() const {return m_age;}
};

person::person(person&& other) :m_name{other.m_name}, m_age{other.m_age}
{
    std::cout << "ムーブコンストラクター呼び出し"<< std::endl;
}

class home
{
    int* m_land;
public:
    explicit home(std::size_t size) :m_land{new int[size]} {}
    ~home(){delete [] m_land;}
    home(home&& other);
    int* land() const{ return m_land;}
};

home::home(home&& other) : m_land{other.m_land}
{
    other.m_land = nullptr;
}

int identity(int v)
{
    return v;
}

int square(int v){
    return v * v;
}

void filtered_show(int (&array)[5], bool (*predicate)(int))
{
    for (int e : array)
    {
        if (predicate(e))
        {
            std::cout << e << std::endl;
        }
    }
}

bool is_odd(int v) {
    return (v % 2) == 1;
}

bool is_less_than_5(int v)
{
    return v < 5;
}

int main(){
    Marker m;
    std::cout << "値渡し前" << std::endl;
    copy(m);
    std::cout << "値渡し後" << std::endl;

    std::cout << "参照渡し前" << std::endl;
    reference(m);
    std::cout << "参照渡し後" << std::endl;

    Object obj{"とても大きなオブジェクト"};
    const std::string& name = obj.get_name();
    std::cout << name << std::endl;

    int i = 42;
    auto& j = id(i);
    j = 0;
    std::cout << i << std::endl;

    person alice{"alice", 15};
    person move{std::move(alice)};

    std::cout << move.name() << std::endl;
    std::cout << move.age() << std::endl;

    home A{100};

    std::cout << "Aの土地のアドレス" << A.land() << std::endl;

    home B{std::move(A)};
    std::cout << "Bの土地のアドレス" << B.land() << std::endl;
    std::cout << "Aの土地のアドレス" << A.land() << std::endl;

    int(*func) (int) = &identity;
    std::cout << "func(4): " << func(4) << std::endl;

    func = &square;
    std::cout << "func(4): " << func(4) << std::endl;

    int array[] = {5, 10, 3, 0, 1};
    filtered_show(array, &is_odd);
    std::cout << std::endl;
    filtered_show(array, &is_less_than_5);
}