/*
Option 6
[Task 3 - quick sort without recursion]

To compare the two sorting methods, create a table (see
table 3) of the following type (data obtained experimentally) for N=1000,
10000, 100000, 500000, 1000000 (N is the number of elements in the array).

To do this, the program must include points for measuring time to
display the execution time of the algorithm.

*/

#include <time.h>

#include <chrono>
#include <cstdlib>
#include <iostream>

using namespace std;

void create_rnd_arr(short int arr[], int min_ch, int max_ch, int n);
void output_arr(short int arr[], int n);

void swap(int& a, int& b);
int rarefaction(short int arr[], int low, int high);
void quick_sort(short int arr[], int low, int high);

int main() {
    time_t t;
    srand(time(&t));

    int min_ch = 16060;
    int max_ch = 36706;

    cout << "\n[Task 3 (quick sort without recursion)]" << endl;

    int n;
    cout << "\nEnter number of series in the array: ";
    cin >> n;
    short int arr[n];
    create_rnd_arr(arr, min_ch, max_ch, n);

    auto start = chrono::steady_clock::now();
    cout << "START" << endl;
    quick_sort(arr, 0, n - 1);

    auto dur = chrono::steady_clock::now() - start;
    cout << "\nN=" << n << ", time: " << chrono::duration_cast<chrono::milliseconds>(dur).count() << " mcs"
         << endl;
    cout << "END" << endl;
}

void create_rnd_arr(short int arr[], int min_ch, int max_ch, int l) {
    cout << l << endl;
    for (int i = 0; i <= l; i++) {
        // num = m + rand() % (n - m + 1);
        arr[i] = rand() % (max_ch - min_ch + 1) + min_ch;
        if (i % 1000 == 0) {
            cout << i << " " << arr[i] << endl;
        }

        if (arr[i] < 0) {
            arr[i] *= -1;
        }
    }
}

void output_arr(short int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << "  ";
    cout << "\n";
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int rarefaction(short int arr[], int low, int high) {
    int opora = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < opora) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quick_sort(short int arr[], int low, int high) {
    int stack[high - low + 1];
    int top = -1;

    stack[++top] = low;
    stack[++top] = high;

    while (top >= 0) {
        high = stack[top--];
        low = stack[top--];

        int opora_index = rarefaction(arr, low, high);

        if (opora_index - 1 > low) {
            stack[++top] = low;
            stack[++top] = opora_index - 1;
        }

        if (opora_index + 1 < high) {
            stack[++top] = opora_index + 1;
            stack[++top] = high;
        }
    }
}