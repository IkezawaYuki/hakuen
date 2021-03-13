#include <iostream>
#include <vector>
using namespace std;

void bubble_sort();

int main() {
    bubble_sort();
    return 0;
}


void bubble_sort() {
    int n;
    short swap_check = 1;
    cout << "Enter the amount of numbers to sort: ";
    cin >> n;
    vector<int> numbers;
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        numbers.push_back(num);
    }

    for (int i = 0; (i < n) && (swap_check == 1); i++){
        swap_check = 0;
        for (int j = 0; j < n-1-i; j++){
            if (numbers[j] > numbers[j+1]) {
                swap_check = 1;
                swap(numbers[j], numbers[j+1]);
            }
        }
    }

    cout << "\nSorted Array : ";
    for (int i = 0; i < numbers.size(); i++) {
        if (i != numbers.size()-1) {
            cout << numbers[i] << ",";
        } else {
            cout << numbers[i] << endl;
        }
    }
}