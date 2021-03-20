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
//void binary_search();
//void linear_search();
void ternary_search();
void decimal();
void decimal_to_binary();
void decimal_to_hexa();
void euclidean();
void tower_of_hanoi();
void palindrome();
void hundred_doors();

int main() {
//    bubble_sort();
//    selection_sort();
//    merge_sort();
//    insertion_sort();
//    shell_sort();
//    counting_sort();
//    binary_search();
//    linear_search();
//    ternary_search();
//    decimal_to_binary();
//    decimal_to_hexa();
//    euclidean();
//    tower_of_hanoi();
//    palindrome();
    hundred_doors();
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

//int it_ternary_search(int left, int right, int A[], int target){
//    while (1) {
//        if (left < right) {
//            if (right - left < absolutePrecision) {
//                for (int i = left; i <= right; i++) {
//                    if (A[i] == target) {
//                        return i;
//                    }
//                }
//                return -1;
//            }
//
//            int oneThird = (left + right) / 3 + 1;
//            int twoThird = (left + right) * 2 / 3 + 1;
//
//            if (A[oneThird] == target) {
//                return oneThird;
//            } else if (A[twoThird] == target) {
//                return twoThird;
//            } else if (target > A[twoThird]) {
//                left = twoThird + 1;
//            } else if (target < A[oneThird]) {
//                right = oneThird - 1;
//            } else {
//                left = oneThird + 1; right = twoThird - 1;
//            }
//        } else {
//            return -1;
//        }
//    }
//}
//
//int rec_ternary_search(int left, int right, int A[], int target) {
//    if (left < right) {
//        if (right - left < absolutePrecision) {
//            for (int i = left; i < right; i++) {
//                if (A[i] == target){
//                    return i;
//                }
//            }
//            return -1;
//        }
//
//        int oneThird = (left + right) / 3 + 1;
//        int twoThird = (left + right) * 2 / 3 + 1;
//
//        if (A[oneThird] == target) {
//            return oneThird;
//        } else if (A[twoThird] == target) {
//            return twoThird;
//        } else if (A[oneThird] > target) {
//            left = oneThird - 1;
//            return rec_ternary_search(twoThird+1, right, A, target);
//        } else if (A[twoThird] < target) {
//            return rec_ternary_search(left, right-1, A, target);
//        }
//
//        return rec_ternary_search(oneThird+1, twoThird-1, A, target);
//    } else {
//        return -1;
//    }
//}


//void ternary_search(int N, int A[], int target) {
//    cout << it_ternary_search(0, N, A, target) << "\t";
//    cout << rec_ternary_search(0, N, A, target) << "\t";
//    cout << "\n";
//}

int InterpolationSearch(int A[], int N, int x) {
    int low = 0;
    int high = N - 1;
    while (low <= high) {
        int mid = low + (((high - 1) * (x - A[low])) / (A[high] - A[low]));
        if (x == A[mid]) {
            return mid;
        } else if (x < A[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

void interpolation_search(){
    int A[] = {2, 4, 5, 7, 13, 14, 15, 23};
    int x = 17;
    int index = InterpolationSearch(A, 8, x);
    if (index != -1)
        std::cout << "Number " << x << " is at " << index;
    else
        std::cout << "Number " << x << " not found";
}


#include "queue"
#include "vector"
#include "cstdio"

#define INF 10000010
vector<pair<int, int>> graph[5 * 100001];
int dis[5*100001];

int dij(vector<pair<int, int>> *v, int s, int *dis) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, s));
    dis[s] = 0;
    int u;
    while(!pq.empty()) {
        u = (pq.top()).second;
        pq.pop();
        for (auto it = v[u].begin(); it != v[u].end(); it++) {
            if (dis[u] + it-> first < dis[it-> second]) {
                dis[it->second] = dis[u] + it->first;
                pq.push(make_pair(dis[it->second], it->second));
            }
        }
    }
}

void djikstra() {
    int m, n, l, x, y, s;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &x, &y, &l);
        graph[x].push_back(make_pair(l, y));
        graph[y].push_back(make_pair(l, x));
    }
    scanf("%d", &s);
    for (int i = 1; i < n; i++) {
        dis[i] = INF;
    }
    dij(graph, s, dis);

    for (int i = 1; i < n; i++) {
        if (dis[i] == INF) {
            cout << "-1 ";
        } else {
            cout << dis[i] << "";
        }
    }
}
//
//#include <bits/stdc++.h>
//class graph{
//    int v;
//    list<int> *adj;
//
//public:
//    graph(int v);
//    void addedge(int src, int dest);
//    void printgraph();
//    void bfs(int s);
//};
//
//graph::graph(int v) {
//    this->v = v;
//    this->adj = new list<int>[v];
//}
//
//void graph::addedge(int src, int dest) {
//    src--;
//    dest--;
//    adj[src].push_back(dest);
//}
//
//void graph::printgraph() {
//
//}

template <class T>
T maxt(T x, T y) {
    if (x > y) {
        return x;
    } else {
        return y;
    }
}


void decimal_to_binary() {
    int number;
    cout << "enter the number:";
    cin >> number;
    int remainder, binary = 0, var = 1;
    do {
        remainder = number % 2;
        number = number / 2;
        binary = binary + (remainder * var);
        var = var * 10;
    } while(number > 0);
    cout << "the binary is :";
    cout << binary;
    cout << endl;
}

void decimal_to_hexa(){
    int valueToConvert = 0;
    int hexArray[8];
    int i = 0;
    char HexValue[] = "0123456789ABCDEF";

    cout << "Enter a Decimal Value" << endl;
    cin >> valueToConvert;

    while (valueToConvert > 15) {
        hexArray[i++] = valueToConvert % 16;
        valueToConvert /= 16;
    }
    hexArray[i] = valueToConvert;

    cout << "Hex Value: ";
    while (i >= 0) {
        cout << HexValue[hexArray[i--]];
    }
    cout << endl;
}

int gcd(int a, int b) {
    if (a == 0) {
        return b;
    }
    if (b == 0) {
        return a;
    }

    if (a == b) {
        return a;
    }
    if (a > b) {
        return gcd(a-b, b);
    }
    return gcd(a, b-a);
}

void euclidean(){
    int a = 98;
    int b = 57;
    cout << "GCD of " << a << " and " << b << " is " << gcd(a, b);
}

struct tower {
    int value[10];
    int top;
} F, U, T;

void show(){
    cout << "\n\n\tF : ";
    for (int i = 0; i < F.top; i++) {
        cout << F.value[i] << "\t";
    }
    cout << "\n\tU : ";
    for (int i = 0; i < U.top; i++) {
        cout << U.value[i] << "\t";
    }
    cout << "\n\tU : ";
    for (int i = 0; i < T.top; i++) {
        cout << T.value[i] << "\t";
    }
}

void mov(tower &From, tower &To) {
    --From.top;
    To.value[To.top] = From.value[From.top];
    ++To.top;
}

void TH(int n, tower &From, tower &Using, tower &To) {
    if (n == 1) {
        mov(From, To);
        show();
    } else {
        TH(n-1, From, To, Using);
        mov(From, To);
        show();
        TH(n-1, Using, From, To);
    }
}

void tower_of_hanoi() {
    F.top = 0;
    U.top = 0;
    T.top = 0;

    int no;
    cout << "\nEnter number of discs : ";
    cin >> no;

    for (int i = 0; i < no; i++) {
        F.value[F.top++] = i;
    }

    show();
    TH(no, F, U, T);
}

#include <algorithm>

void palindrome(){
    int num;
    cout << "Enter number = ";
    cin >> num;

    string s1 = to_string(num);
    string s2 = s1;

    reverse(s1.begin(), s1.end());

    if (s1 == s2) {
        cout << "true";
    } else {
        cout << "false";
    }
}

void print(bool door[]) {
    cout << "Open Doors:" << endl;
    for (int num = 0; num < 100; num++) {
        if (door[num] == false) {
            cout << "Door #" << num+1 << endl;
        }
    }
}

void hundred_doors(){
    bool Doors[100] = {false};
    for (int pass = 1; pass < 101; pass++) {
        for (int num = pass - 1; num < 100; num += pass) {
            if (Doors[num] == true) {
                Doors[num] = false;
            } else {
                Doors[num] = true;
            }
        }
    }
    print(Doors);
}

#include <string>
#include <sstream>


string bottles_of_beer(int n) {
    stringstream out;
    if (n == 0) {
        out << "one bottle";
    }
    if (n == 1) {
        out << "no more bottles";
    }
    if (n > 1) {
        out << n << "bottles";
    }
    out << "of beer";
    return out.str();
}

#include <vector>

template<typename T>
T kadane_method(const vector<T>& v) {
    T ret = 0;
    for_each(v.begin(), v.end(), [c_max = 0, max = 0, &ret](T m) mutable {
        c_max = c_max + m;
        if (c_max < 0) {
            c_max = 0;
        }
        if (max < c_max){
            max = c_max;
        }
        ret = max;
    });
    return ret;
}
