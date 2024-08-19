#include <time.h>

#include <iomanip>
#include <iostream>

using namespace std;

void create_lake(int lake[][100], int m, int n);
void output_matrix(int matrix[][100], int m, int n);

void solution(int lake[][100], int m, int n);
bool occupied_or_not(int lake[100][100], int i, int j, int m, int n);

struct Cell {
    int i;
    int j;
    int distance;
};

const int coord_i[] = {0, 0, -1, 1};
const int coord_j[] = {-1, 1, 0, 0};

int main() {
    time_t t;
    srand(time(&t));

    int m;
    cout << "Enter m: ";
    cin >> m;
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "\n";

    int lake[100][100];

    cout << "[Task 3 - Lake]" << endl;

    create_lake(lake, m, n);
    cout << "Lake: \n\n";
    output_matrix(lake, m, n);

    solution(lake, m, n);

    lake[0][0] = 0;
    cout << "\nPath: \n\n";
    output_matrix(lake, m, n);
}

void create_lake(int lake[][100], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int random = rand() % 10;
            if (random <= 2) {
                lake[i][j] = -1;
            } else
                lake[i][j] = 0;
        }
    }
    lake[0][0] = 0;
    lake[m - 1][n - 1] = 0;
}

void output_matrix(int matrix[][100], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(2) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

bool occupied_or_not(int lake[][100], int i, int j, int m, int n) {
    return i >= 0 && i < m && j >= 0 && j < n && lake[i][j] == 0;
}

void solution(int lake[][100], int m, int n) {
    Cell queue[m * n + 1];
    int qStart = 0, qEnd = 1;
    queue[qStart].distance = 0;
    queue[qStart].i = 0;
    queue[qStart].j = 0;

    while (qStart < qEnd) {
        Cell curr = queue[qStart++];
        if (curr.i == m - 1 && curr.j == n - 1) {
            cout << "\nShortest distance is " << curr.distance << endl;
            return;
        }
        for (int k = 0; k < 4; k++) {
            int I = curr.i + coord_i[k], J = curr.j + coord_j[k];

            if (occupied_or_not(lake, I, J, m, n)) {
                lake[I][J] = curr.distance + 1;
                queue[qEnd].distance = curr.distance + 1;
                queue[qEnd].i = I;
                queue[qEnd++].j = J;
            }
        }
    }
    cout << "\nPath not found!\n" << endl;
}
