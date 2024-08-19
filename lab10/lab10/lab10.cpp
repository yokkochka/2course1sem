#include <iostream>
#include <time.h>
#include <chrono>
using namespace std;



int find_max_sum_of_squares(int array[], int n) {
    int max_sum = 0;
    int current_sum;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (abs(array[i] - array[j]) > 3) {
                current_sum = array[i] * array[i] + array[j] * array[j];
                max_sum = max(max_sum, current_sum);
            }
        }
    }
    return max_sum;
}

void rand_mas(int* array, int n) {
    for (int i = 0; i < n; i++)
    {
        array[i] = 0 + rand() % (1000 - 0 + 0);
        if (array[i] < 0) { array[i] *= -1; }
    }
}



int main() {
    setlocale(LC_ALL, "rus");
    time_t t;
    srand(time(&t));
    int n;
    cout << "Enter the number of sequence elements: ";
    cin >> n;

    while (3 > n > 10000) {
        cout << "The maximum number of elements has been exceeded" << endl;
        cout << "Enter the number of sequence elements: "; cin >> n;
    }

    
    int* array = new int[n];
    rand_mas(array, n);
    
    auto start = chrono::steady_clock::now();
    int result = find_max_sum_of_squares(array, n);
    auto dur = chrono::steady_clock::now() - start;

    cout << "Maximum sum of squares of two elements:" << result << endl;
    cout << "time: " << chrono::duration_cast<chrono::microseconds>(dur).count() << " mcs" << endl;

    delete[] array;
}
