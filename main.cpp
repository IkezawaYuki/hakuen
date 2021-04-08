#include <iostream>

using namespace std;

class S{
    static int count;
public:
    S();
    ~S();
    static void show_count();
};

int S::count = 0;

S::S(){
    ++count;
}

S::~S() {
    --count;
}

void S::show_count() {
    cout << "S::count: " << count << endl;
}

int main() {
    S::show_count();
    S a;
    a.show_count();
    S b;
    b.show_count();
    S c;
    c.show_count();
}