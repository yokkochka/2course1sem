/*
2. Using a random number generator, get 200 numbers in the range from 0 to 1.
Evaluate the uniformity of distribution based on them. Split interval (0,1) into intervals
equal length [0..0,1], [0,1..0,2], …,[0,9..1] and build a horizontal histogram
(bar chart) showing how many numbers fall into each interval.

Example of a histogram:
0.0..0.1 *******
0.1..0.2 ********
...
0.9..1.0 *******
*/

#include <stdlib.h>
#include <time.h>

#include <iostream>

using namespace std;

void output_stars(int var);

int main() {
    time_t t;
    srand(time(&t));

    double arr_of_rnd[200];
    for (int i = 0; i < 200; i++) {
        arr_of_rnd[i] = rand() % 1000 / 1000.0;
    }

    cout << "\n[Task2]\n" << endl;
    cout << "Output: \n" << endl;
    for (int i = 0; i < 200; i++) {
        cout << arr_of_rnd[i] << " ";
        if (i % 10 == 0) {
            cout << endl;
        }
    }
    cout << endl;

    int statistic[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 200; i++) {
        statistic[int(arr_of_rnd[i] * 10)] += 1;
    }
    cout << "\n";
    for (int i = 0; i < 10; i++) {
        if (i == 0) {
            cout << "0.0"
                 << " - " << i / 10.0 + 0.1 << ":";
            output_stars(statistic[i]);
        } else if (i == 9) {
            cout << i / 10.0 << " - "
                 << "1.0"
                 << ":";
            output_stars(statistic[i]);
        } else {
            cout << i / 10.0 << " - " << i / 10.0 + 0.1 << ":";
            output_stars(statistic[i]);
        }
    }
}

void output_stars(int var) {
    for (int i = 0; i < var; i++) {
        cout << "*";
    }
    cout << endl;
}
