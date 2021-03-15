#include <iostream>
#include <vector>
using namespace std;

void bubble_sort();
void selection_sort();
void merge_sort();
void quick_sort();
void insertion_sort();
void shell_sort();
void counting_sort();
void binary_search();
void linear_search();


int main() {
//    bubble_sort();
//    selection_sort();
//    merge_sort();
//    insertion_sort();
//    shell_sort();
//    counting_sort();
//    binary_search();
    linear_search();
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

int Max(int Arr[], int N) {
    int max = Arr[0];
    for (int i = 1; i < N; i++) {
        if (Arr[i] > max) {
            max = Arr[i];
        }
    }
    return max;
}

int Min(int Arr[], int N) {
    int min = Arr[0];
    for (int i = 1; i < N; i++) {
        if (Arr[i] < min) {
            min = Arr[i];
        }
    }
    return min;
}

void Print(int Arr[], int N) {
    for (int i = 0; i < N; i++) {
        cout << Arr[i] << ", ";
    }
}

int *Counting_Sort(int Arr[], int N) {
    int max = Max(Arr, N);
    int min = Min(Arr, N);

    int *Sorted_Arr = new int[N];
    int *Count = new int[max - min +1];
    for (int i = 0; i < N; i++) {
        Count[Arr[i]-min]++;
    }
    for (int i = 0; i < (max - min + 1); i++) {
        Count[i] += Count[i-1];
    }
    for (int i = N - 1; i >= 0; i--) {
        Sorted_Arr[Count[Arr[i]-min]-1] = Arr[i];
        Count[Arr[i]-min]--;
    }

    return Sorted_Arr;
}

void counting_sort(){
    int Arr[] = {47, 65, 20, 66, 25, 53, 64, 69, 72, 22, 74, 25, 53, 15, 42, 36, 4, 69, 86, 19}, N = 20;
    int *Sorted_Arr;
    cout << "\n\tOrignal Array = ";
    Print(Arr, N);
    Sorted_Arr = Counting_Sort(Arr, N);
    cout << "\n\t Sorted Array = ";
    Print(Sorted_Arr, N);
    cout << endl;
}

int binarySearch(int a[], int l, int r, int key){
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (key == a[m]) {
            return m;
        } else if (key < a[m]) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return -1;
}

void binary_search(){
    int n, key;
    cout << "Enter size of array: ";
    cin >> n;
    cout << "Enter array elements: ";
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << "Enter search key: ";
    cin >> key;

    int res = binarySearch(a, 0, n -1, key);
    if (res != -1){
        cout << key << " found at index " << res << endl;
    } else {
        cout << key << " not found" << endl;
    }
}

int LinearSearch(int *array, int size, int key) {
    for (int i = 0; i < size; ++i) {
        if (array[i] == key) {
            return i;
        }
    }
    return -1;
}

void linear_search(){
    int size;
    cout << "\nEnter the size of the Array : ";
    cin >> size;

    int array[size];
    int key;

    cout << "\nEnter the Array of " << size << " numbers : ";

    for (int i = 0; i < size; ++i) {
        cin >> array[i];
    }

    cout << "\nEnter the number to be searched : ";
    cin >> key;

    int index = LinearSearch(array, size, key);

    if (index != -1) {
        cout << "\nNumber found at index : " << index;
    } else {
        cout << "\nNot found";
    }
}

#define _target 10
#define absolutePrecision = 0
#define MAX 10000000

int N = 21;
int A[MAX] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 3, 4, 10};

void get_input(){
    // todo
}

int it_ternary_search(int left, int right, int A[], int target){
    while (1) {
        if (left < right) {
            if (right - left < absolutePrecision) {
                for (int i = left; i <= right; i++) {

                }
            }
        }
    }
}