#include <iostream>

struct vector2d
{
    int x;
    int y;
};

class Vec2{
    int m_x;
    int m_y;

public:
    int getX() const { return m_x; }
    int getY() const { return m_y; }

    void setX(int x) { m_x = x; }
    void setY(int y) { m_y = y; }
};

template <typename Vector>
void show_vector(Vector v);

template <>
void show_vector<Vec2>(Vector v){
    std::cout << "Vec{x: " << v.getX() << ", y: " << v.getY() << "}"
}

template <typename Vector>
void show_vector<Vector v)
{
    std::cout << "{x: " << v.getX() << ", y: " << v.getY() << "}"
}