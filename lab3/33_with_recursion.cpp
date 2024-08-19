/*
Option 6
[Task 3 - quick sort wih recursion]

To compare the two sorting methods, create a table (see
table 3) of the following type (data obtained experimentally) for N=1000,
10000, 100000, 500000, 1000000 (N is the number of elements in the array).
For this, the program must include points for measuring time to
provide the execution time of the algorithm.
*/

#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

void create_rnd_arr(short int arr[], int min_ch, int max_ch, int n);
void output_arr(short int arr[], int n);
void swap(int& a, int& b);

void quick_sort(short int arr[], int start, int n);
int dop_quick_sort(short int arr[], int start, int end);

int main() {
    time_t t;
    srand(time(&t));

    int min_ch = 16060;
    int max_ch = 36706;

    cout << "\n[Task 3 (quick sort with recursion)]" << endl;

    int n;
    cout << "\nEnter number of series in the array: ";
    cin >> n;

    short int arr[n];

    create_rnd_arr(arr, min_ch, max_ch, n);

    auto start = chrono::steady_clock::now();

    quick_sort(arr, 0, n - 1);

    auto dur = chrono::steady_clock::now() - start;
    cout << "\nN=" << n << ", time: " << chrono::duration_cast<chrono::milliseconds>(dur).count() << " mcs"
         << endl;
}

void create_rnd_arr(short int arr[], int min_ch, int max_ch, int n) {
    for (int i = 0; i <= n; i++) {
        // num = m + rand() % (n - m + 1);
        arr[i] = rand() % (max_ch - min_ch + 1) + min_ch;
        if (arr[i] < 0) {
            arr[i] *= -1;
        }
    }
}

void output_arr(short int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << "  ";
    cout << "\n";
}

void quick_sort(short int arr[], int start, int end) {
    if (start >= end) {
        return;
    }

    int index_opora = dop_quick_sort(arr, start, end);

    quick_sort(arr, start, index_opora - 1);
    quick_sort(arr, index_opora + 1, end);
}

int dop_quick_sort(short int arr[], int start, int end) {
    int opora = arr[end];
    int index_sort = start;
    short int temp;

    for (int i = start; i < end; i++) {
        if (arr[i] <= opora) {
            swap(arr[i], arr[index_sort]);
            index_sort++;
        }
    }
    swap(arr[end], arr[index_sort]);

    return index_sort;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}