/*
Option 6

[Task 1] Develop routines for sorting an array of a certain data type (see Table 1) using sorting algorithms
(see Table 2).

Table 1: One-dimensional array of unsigned short integers of type short int

Table 2:
1. Quick sort
2. Block sort
*/

#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

void create_rnd_arr(short int arr[], int min_ch, int max_ch, int n);
void output_arr(short int arr[], int n);

void fill_arr(short int arr[], short int basket_arr[], int n);

void quick_sort(short int arr[], int start, int n);
int dop_quick_sort(short int arr[], int start, int end);

void basket_sort(short int arr[], int n);
void sorting_one_basket(short int basket[], int n);

int main() {
    time_t t;
    srand(time(&t));

    int min_ch = -1000;
    int max_ch = 1000;

    cout << "\n[Task 1]" << endl;
    int n;
    cout << "\nEnter number of series in the array: ";
    cin >> n;

    short int arr[n];
    short int basket_arr[n];

    create_rnd_arr(arr, min_ch, max_ch, n);

    fill_arr(arr, basket_arr, n);

    cout << "\nArray for quick sort: \n";
    output_arr(arr, n);
    quick_sort(arr, 0, n - 1);
    cout << "\nSorted array by quick sort:\n";
    output_arr(arr, n);

    cout << "\nArray for block sort: \n";
    output_arr(basket_arr, n);
    basket_sort(basket_arr, n);
    cout << "\nSorted array by block sort:\n";
    output_arr(basket_arr, n);
}

void fill_arr(short int arr[], short int basket_arr[], int n) {
    for (int i = 0; i < n; i++) {
        basket_arr[i] = arr[i];
    }
}

void create_rnd_arr(short int arr[], int min_ch, int max_ch, int n) {
    for (int i = 0; i <= n; i++)
        // num = m + rand() % (n - m + 1);
        arr[i] = min_ch + rand() % (max_ch - min_ch + 1);
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
            temp = arr[i];
            arr[i] = arr[index_sort];
            arr[index_sort] = temp;
            index_sort++;
        }
    }
    temp = arr[end];
    arr[end] = arr[index_sort];
    arr[index_sort] = temp;

    return index_sort;
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
