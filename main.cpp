#include <iostream>
#include <vector>
using namespace std;

void bubble_sort();
void selection_sort();
void merge_sort();
void quick_sort();
void insertion_sort();
void shell_sort();

int main() {
//    bubble_sort();
//    selection_sort();
//    merge_sort();
//    insertion_sort();
    shell_sort();
    return 0;
}

void insertion_sort(){
    int n;
    cout << "\nEnter the length of your array : ";
    cin >> n;
    int Array[n];
    cout << "\nEnter any " << n << " Numbers for Unsorted Array : ";

    for (int i = 0; i < n; i++) {
        cin >> Array[i];
    }

    for (int i = 0; i < n; i++) {
        int temp = Array[i];
        int j = i - 1;
        while (j >= 0 && temp < Array[j]) {
            Array[j+1] = Array[j];
            j--;
        }
        Array[j+1] = temp;
    }

    cout << "\nSorted Array :";
    for (int i = 0; i < n; i++) {
        cout << Array[i] << "\t";
    }

}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] =  arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 +j];
    }

    i = 0;
    j = 0;
    k = l;
    while(i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
          arr[k] = R[j];
          j++;
        }
        k++;
    }


    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

void show(int A[], int size){
    int i;
    for (i = 0; i < size; i++) {
        cout << A[i] << "\n";
    }
}

void merge_sort(){
    int size;
    cout << "\nEnter the number of elements : ";

    cin >> size;
    int array[size];

    cout << "\nEnter the unsorted elements : ";

    for (int i = 0; i < size; ++i) {
        cout << "\n";
        cin >> array[i];
    }
    mergeSort(array, 0, size);
    cout << "Sorted array\n";
    show(array, size);

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

void selection_sort(){
    int Array[6];
    cout << "\nEnter any 6 Numbers for Unsorted Array : ";

    for (int & i : Array) {
        cin >> i;
    }

    for (int i = 0; i < 6; i++) {
        int min = i;
        for (int j = i + 1; j < 6; j++) {
            if (Array[j] < Array[min]) {
                min = j;
            }
        }
        int temp = Array[i];
        Array[i] = Array[min];
        Array[min] = temp;
    }

    cout << "\nSorted Array :";
    for (int j : Array) {
        cout << j << "\t";
    }
}

int partition(int arr[], int low, int high) {
    int i = 0;
    int pivot = (low + high) / 2;
    for (int j = 0; j < high; j++){
        if (arr[j] <= pivot){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high){
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p, high);
    }
}

void quick_sort(){
    int size;
    cout << "\nEnter the number of elements : ";
    cin >> size;
    int arr[size];
    cout << "\nEnter the unsorted elements : ";

    for (int i = 0; i < size; ++i) {
        cout << "\n";
        cin >> arr[i];
    }
    quickSort(arr, 0, size);
    cout << "Sorted array\n";
    show(arr, size);
}

void shell_sort(){
    int size = 10;
    int array[size];
    cout << "\nHow many numbers do want to enter in unsorted array : ";
    cin >> size;
    cout << "\nEnter the numbers for unsorted array : ";
    for (int i = 0; i < size; i++){
        cin >> array[i];
    }

    for (int i = size / 2; i > 0; i = i / 2) {
        for (int j = i; j < size; j++) {
            for (int k = j - i; k >= 0; k = k - i){
                if (array[k] < array[k+i]) {
                    break;
                } else {
                    int temp = array[k + i];
                    array[k+i] = array[k];
                    array[k] = temp;
                }
            }
        }

        cout << "\nSorted array :";
        for (int i = 0; i < size; ++i) {
            cout << array[i] << "\t";
        }
    }
}