#include <iostream>

using namespace std;

class S{
public:
    int answer = 42;
    float pi{ 3.141592f };
};

class Book {
    string title = "";
    int page = 0;
public:
    Book();
    explicit Book(string title, int page);
    void show() const;
};

Book::Book() :title("untitled") {

}

Book::Book(string title, int page) :title(title), page(page) {

}

void Book::show() const {
    cout << title << " " << page << "ページ" << endl;
}

int main(){
    Book nsdmi;
    nsdmi.show();
    Book old_edition{"独習C++", 543};
    old_edition.show();
}