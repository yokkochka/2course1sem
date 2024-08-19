/*
[Task 4] - Create an algorithm and write a program that finds a string of length
100 characters, consisting only of the letters "A", "B", "C", such that no two adjacent substrings in it are
equal to each other. Use brute force with backtracking.
*/

#include <time.h>

#include <iostream>
#include <string>

using namespace std;

bool isValidSubstring(const string& str);

int main() {
    string random_string;

    time_t t;
    srand(time(&t));

    int n;
    cout << "Enter string lenght(>100): ";
    cin >> n;
    while (n < 100) {
        cout << "Enter string lenght(>100): ";
        cin >> n;
    }
    for (int i = 0; i < n; ++i) {
        int random = rand() % 3;
        if (random == 0) {
            random_string += 'A';
        } else if (random == 1) {
            random_string += 'B';
        } else if (random == 2) {
            random_string += 'C';
        }
    }
    cout << "\n[Task 3] - strings\n" << endl;
    cout << "Generated random string (lenght " << n << ") : " << random_string << "\n\n" << endl;
    for (int i = 0; i <= random_string.length() - 100; ++i) {
        if (isValidSubstring(random_string.substr(i, 100))) {
            cout << "Substring found at position " << i << ": " << random_string.substr(i, 100) << endl;
            return 0;
        }
    }

    cout << "The required substring was not found" << endl;
}

bool isValidSubstring(const string& str) {
    for (int i = 0; i < str.length() - 2; ++i) {
        if (str.substr(i, 3) == str.substr(i + 3, 3)) {
            return false;
        }
    }
    return true;
}