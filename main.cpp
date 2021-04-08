#include <iostream>

using namespace std;

string get_message();

class A{
public:
    ~A();
};

A::~A() {
    cout << "デストラクター呼び出し" << endl;
}

void function_scope(int i) {
    A a;
    cout << "関数スコープ" << endl;
    if (i > 0) {
        return;
    }
    cout << "if文のあと" << endl;
}


int main(){
    cout << "__FILE__:" << __FILE__ << endl;
    cout << "__LINE__:" << __LINE__ << endl;
    cout << "__func__:" << __func__ << endl;
    cout << "__cplusplus:" << __cplusplus << endl;
    int line = __LINE__;
    cout << "line:" << line << ", __LINE__" << __LINE__ << endl;

    auto msg = get_message();
    cout << msg << endl;

    function_scope(10);
    cout << endl;
    function_scope(-10);

    if (true) {
        cout << "if文" << endl;
        A a;
    }

    cout << endl;

    for (int i = 0; i < 5;i++) {
        cout << "for文(" << i << ")" << endl;
        A a;
    }

    cout << endl;

    {
        cout << "ただのスコープ" << endl;
        A a;
    }

    cout << endl;

    cout << "main()関数の最後" << endl;

    int i = 42;
    {
        int i = 72;

        cout << "innner: " << &i << ": " << i << endl;
        i = 0;
    }

    cout << "outer: " << &i << ": " << i << endl;
}

string get_message(){
    return "hello, forward declaration";
}