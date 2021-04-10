#include <memory>
#include <utility>
#include <iostream>

class A{
public:
    A()
    {
        std::cout << "コンストラクター" << std::endl;
    }

    ~A()
    {
        std::cout << "デストラクター" << std::endl;
    }
};

std::unique_ptr<A> allocate()
{
    std::cout << "allocate()" << std::endl;
    std::unique_ptr<A> ptr{new A{}};
    return std::move(ptr);
}

class Counter {
    int value;
public:
    Counter() :value{0} {}

    int operator()();
    int operator()(int n);

    void show() const;
};

int Counter::operator()() {
    return ++value;
}

int Counter::operator()(int n) {
    return value += n;
}

void Counter::show() const {
    std::cout << "Counter.value" << value << std::endl;
}

class Integer {
    int value;
public:
    Integer(int value) : value{value} {}
    Integer& operator=(const Integer& rhs);

    Integer& operator+=(const Integer& rhs);
    Integer& operator-=(const Integer& rhs);
    Integer& operator*=(const Integer& rhs);
    Integer& operator/=(const Integer& rhs);

    void show() const;
};

Integer& Integer::operator+=(const Integer &rhs) {
    value += rhs.value;
    return *this;
}

Integer& Integer::operator-=(const Integer &rhs) {
    value -= rhs.value;
    return *this;
}

Integer& Integer::operator*=(const Integer &rhs) {
    value *= rhs.value;
    return *this;
}

Integer& Integer::operator/=(const Integer &rhs) {
    value /= rhs.value;
    return *this;
}

Integer& Integer::operator=(const Integer &rhs) {
    std::cout << "コピー: " << value << " -> " << rhs.value << std::endl;
    value = rhs.value;
    return *this;
}

void Integer::show() const {
    std::cout << "value: " << value << std::endl;
}

class heap {
    int* i;

public:
    heap() : i{nullptr} { }
    ~heap()
    {
        delete i;
    }
    bool create();
    operator bool() const;
};

bool heap::create() {
    if (*this)
    {
        return false;
    }
    i = new int{};
    *i = 0;
    return true;
}

heap::operator bool() const {
    return i != nullptr;
}

class vector4d {
    float x, y, z, w;

public:
    explicit vector4d(float x, float y, float z, float w) : x{x}, y{y}, z{z}, w{w} {}
    friend vector4d add(const vector4d& lhs, const vector4d& rhs);
};

vector4d add(const vector4d& lhs, const vector4d& rhs)
{
    vector4d ret {
        lhs.x + rhs.x,
        lhs.y + rhs.y,
        lhs.z + rhs.z,
        lhs.w + rhs.w,
    };
    return ret;
}

class vector3d{
    float x, y, z;
public:
    explicit vector3d(float x, float y, float z) : x{x}, y{y}, z{z}, {}
    operator vector4d() const;
};

vector3d::operator vector4d() const {
    vector4d ret{x, y, z, 0.0f};
    return ret;
}

int main(){
    {
        std::unique_ptr<A> ptr;
        std::cout << "関数呼び出しの前" << std::endl;
        ptr = allocate();
        std::cout << "関数呼び出しの後" << std::endl;
    }
    std::cout << "スコープのあと" << std::endl;

    Counter c;
    c();
    c();
    c();
    c.show();
    c(-3);
    c.show();

    Integer x = 10;
    Integer y = 3;
    Integer z = 7;

    z *= x;
    y /= y;
    x -= y;
    x += z;

    x.show();

    heap h;
    if (!h) {
        std::cout << "変換関数がfalseが返しました" << std::endl;
    }

    std::cout << "heap::create呼び出し" << std::endl;
    h.create();

    if (!h) {
        std::cout << "変換関数がfalseが返しました" << std::endl;
    }

    std::cout << "終了" << std::endl;

    vector3d v1{1,2,3}, v2{0,1,0};
    vector4d a = v1;
    vector4d b = v1 + v2;
}