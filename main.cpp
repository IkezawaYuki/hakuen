#include <iostream>
using namespace std;

class product {
    int id;
public:
    int get_id() const;
    int get_id();
    void set_id(int new_id);
};

int product::get_id() const{
    return id;
}

void product::set_id(int new_id) {
    id = new_id;
}

class heavy_class {
    int m_value;
    mutable int m_cache;
    mutable bool m_cache_valid;

public:
    int generate() const;
    void set(int value);
    int get() const;
};

int heavy_class::generate() const {
    cout << "とても重いデータ生成関数" << endl;
    return m_value;
}

void heavy_class::set(int value) {
    m_cache_valid = false;
    m_value = value;
}

int heavy_class::get() const {
    if (m_cache_valid) {
        return m_cache;
    }
    m_cache = generate();
    m_cache_valid = true;
    return m_cache;
}

int main(){
    heavy_class heavy_object;
    heavy_object.set(100);
    cout << heavy_object.get() << endl;
    cout << heavy_object.get() << endl;
    heavy_object.set(200);
    cout << heavy_object.get() << endl;
    cout << heavy_object.get() << endl;
}