/*
Option 6

[Task 3] To compare sorting algorithms, create a table (see Table 3) of the following type (obtain data
experimentally) for N=100, 200, 300, 400, 500. (N is the number of elements in the array). For this, the
program must include points for measuring time to display the execution time of the algorithm.
*/

#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

void create_rnd_arr(short int arr[], int min_ch, int max_ch, int n);
void output_arr(short int arr[], int n);

void basket_sort(short int arr[], int n);
void sorting_one_basket(short int basket[], int n);

int main() {
    time_t t;
    srand(time(&t));

    int min_ch = 16060;
    int max_ch = 36706;

    cout << "\n[Task 3 (basket sort)]" << endl;
    int n;
    cout << "\nEnter number of series in the array: ";
    cin >> n;

    auto start = chrono::steady_clock::now();

    short int arr[n];

    create_rnd_arr(arr, min_ch, max_ch, n);
    cout << "\nArray for block sort: \n";
    output_arr(arr, n);

    basket_sort(arr, n);

    cout << "\nSorted array by block sort:\n";
    output_arr(arr, n);

    auto dur = chrono::steady_clock::now() - start;
    cout << "N=" << n << ", time: " << chrono::duration_cast<chrono::microseconds>(dur).count() << " mcs"
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

void basket_sort(short int arr[], int n) {
    short int min_val = arr[0];
    short int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    int num_baskets = n;
    int basket_sizes[num_baskets] = {0};
    short int* baskets[num_baskets];

    for (int i = 0; i < num_baskets; i++) {
        baskets[i] = new short int[n];
    }

    for (int i = 0; i < n; i++) {
        int basket_index = int((arr[i] - min_val) / (max_val - min_val) * (num_baskets - 1));

        baskets[basket_index][basket_sizes[basket_index]] = arr[i];

        basket_sizes[basket_index]++;
    }

    for (int i = 0; i < num_baskets; i++) {
        sorting_one_basket(baskets[i], basket_sizes[i]);
    }

    int index = 0;
    for (int i = 0; i < num_baskets; i++) {
        for (int j = 0; j < basket_sizes[i]; j++) {
            arr[index++] = baskets[i][j];
        }
        delete[] baskets[i];
    }
}

void sorting_one_basket(short int basket[], int n) {
    for (int i = 1; i < n; i++) {
        short int key = basket[i];
        int j = i - 1;
        while (j >= 0 && basket[j] > key) {
            basket[j + 1] = basket[j];
            j--;
        }
        basket[j + 1] = key;
    }
}
