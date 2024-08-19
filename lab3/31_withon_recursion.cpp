/*
Option 6
[Task 1 - quick sort without recursion]

Develop a program to quickly sort an array of a certain
data type short int without recursion.
*/

#include <time.h>

#include <cstdlib>
#include <iostream>
using namespace std;

void create_rnd_arr(short int arr[], int min_ch, int max_ch, int n);
void output_arr(short int arr[], int n);

void swap(int& a, int& b);
int rarefaction(short int arr[], int low, int hight);
void quick_sort(short int arr[], int low, int hight);

int main() {
    time_t t;
    srand(time(&t));

    int min_ch = 0;
    int max_ch = 1000;

    cout << "\n[Task 1 (quick sort without recursion)]" << endl;

    int n;
    cout << "\nEnter number of series in the array: ";
    cin >> n;
    short int arr[n];

    create_rnd_arr(arr, min_ch, max_ch, n);
    cout << "\nArray for quick sort: \n";
    output_arr(arr, n);

    quick_sort(arr, 0, n - 1);

    cout << "\nSorted array by quick sort:\n";
    output_arr(arr, n);
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

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int rarefaction(short int arr[], int low, int hight) {
    int opora = arr[hight];
    int i = (low - 1);

    for (int j = low; j <= hight - 1; j++) {
        if (arr[j] < opora) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[hight]);
    return (i + 1);
}

void quick_sort(short int arr[], int low, int hight) {
    int stack[hight - low + 1];
    int top = -1;

    stack[++top] = low;
    stack[++top] = hight;

    while (top >= 0) {
        hight = stack[top--];
        low = stack[top--];

        int opora_index = rarefaction(arr, low, hight);

        if (opora_index - 1 > low) {
            stack[++top] = low;
            stack[++top] = opora_index - 1;
        }

        if (opora_index + 1 < hight) {
            stack[++top] = opora_index + 1;
            stack[++top] = hight;
        }
    }
}