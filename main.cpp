#include <iostream>
using namespace std;

struct vector2d {
    int x;
    int y;
};

int add(int left, int right) {
    return left + right;
}

double add(double left, double right) {
    return left + right;
}

vector2d add(vector2d left, vector2d right) {
    vector2d v;
    v.x = left.x + right.x;
    v.y = left.y + right.y;
    return v;
}

int main(){
    int integer = add(1, 2);
    cout << integer << endl;

    double floating = add(3.14, 42.195);
    cout << floating << endl;

    vector2d v = {1, 2};
    vector2d u = {-3, 4};

    vector2d w = add(v, u);
    cout << w.x << ", " << w.y << endl;
}