#include <iostream>
#include <cstdlib>
#include <time.h>
#include <chrono>
using namespace std;

int findMaxSumOfSquares(int array[], int n) {
    int maxSum = 0;
    int max1 = array[0];
    int max2 = array[1];

    if (max2 > max1) {
        swap(max1, max2);
    }

    for (int i = 2; i < n; ++i) {
        if (array[i] > max1) {
            max2 = max1;
            max1 = array[i];
        }
        else if (array[i] > max2 && abs(max1 - array[i]) > 3 ) {
            max2 = array[i];
        }
    }

    maxSum = max1 * max1 + max2 * max2;
    return maxSum;
}

void randMas(int array[], int n) {
    for (int i = 0; i < n; ++i) {
        array[i] = rand() % 1000;
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
        cout << "Enter the number of sequence elements: ";
        cin >> n;
    }

    int array[10000];
    randMas(array, n);

    auto start = chrono::steady_clock::now();
    int result = findMaxSumOfSquares(array, n);
    auto dur = chrono::steady_clock::now() - start;
    
    cout << "Maximum sum of squares of two elements : " << result << endl;

    cout <<"time: " << chrono::duration_cast<chrono::microseconds>(dur).count() << " mcs" << endl;

}
