/*
1. A randomly selected number is stored in a variable. The variable type is selected from the variable type
table (float)
*/

#include <time.h>

#include <iostream>

using namespace std;

int main() {
    time_t t;
    srand(time(&t));

    float rnd = rand();
    cout << "\n[Task1] Random variable: " << rnd << "\n\n";
}
