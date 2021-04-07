#include <iostream>

using namespace std;

class vector3d{
    float x;
    float y;
    float z;

public:
    vector3d();
    explicit vector3d(float x, float y, float z);
    friend vector3d add(const vector3d& lhs, const vector3d& rhs);
    void dump() const;
};

vector3d::vector3d() : vector3d(0, 0, 0) {

}

vector3d::vector3d(float x, float y, float z) :x(x), y(y), z(z){

}

vector3d add(const vector3d& lhs, const vector3d& rhs) {
    vector3d result;
    result.x = lhs.x + rhs.x;
    result.y = lhs.y + rhs.y;
    result.z = lhs.z + rhs.z;
    return result;
}

void vector3d::dump() const {
    cout << x << ", " << y << ", " << z << endl;
}

class S{
public:
    static int num;
};

int S::num = 123;

int main(){
    vector3d a(1,1,1), b(1,2,3);
    vector3d c = add(a, b);
    c.dump();

    cout << S::num << endl;
    S::num = 456;
    S s;
    cout << s.num << endl;
}