#include <iostream>
using namespace std;

int main(){
    int value = 42;
    int other = 0;
    int* pointer = &value;
    int& reference = value;

    cout << "valueのアドレスは" << &value << "で、値は" << value << "です" << endl;
    cout << "otherのアドレスは" << &other << "で、値は" << other << "です" << endl;
    cout << "pointerのアドレスは" << pointer << "で、値は" << *pointer << "です" << endl;
    cout << "referenceのアドレスは" << &reference << "で、値は" << reference << "です" << endl;

    pointer = &other;
    reference = other;

    cout << endl;

    cout << "valueのアドレスは" << &value << "で、値は" << value << "です" << endl;
    cout << "otherのアドレスは" << &other << "で、値は" << other << "です" << endl;
    cout << "pointerのアドレスは" << pointer << "で、値は" << *pointer << "です" << endl;
    cout << "referenceのアドレスは" << &reference << "で、値は" << reference << "です" << endl;

}