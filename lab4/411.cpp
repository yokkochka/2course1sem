/*
[Option 6]
1. Write a program to find the shortest distances from the 1st vertex to
all others for a graph according to your option (see Fig. 11),
using Floyd's algorithm. Make a table
comparing the two algorithms by time or number of steps.
*/

#include <chrono>
#include <iomanip>
#include <iostream>
using namespace std;

const int max_vertices = 8;
const int INF = 1e9;

void solution(int graph[][max_vertices], int distances[][max_vertices]);
void output_distances(int distances[][max_vertices]);

int main() {
    int graph[max_vertices][max_vertices] = {{0, 3, 0, 0, 0, 0, 0, 1}, {3, 0, 0, 3, 0, 0, 2, 2},
                                             {0, 0, 0, 4, 0, 0, 3, 0}, {0, 2, 4, 0, 5, 7, 0, 0},
                                             {0, 0, 0, 5, 0, 6, 0, 0}, {0, 0, 0, 7, 6, 0, 4, 5},
                                             {0, 2, 3, 0, 0, 4, 0, 1}, {1, 2, 0, 0, 0, 5, 1, 0}};

    auto start = chrono::steady_clock::now();

    cout << "\n[Task 1] - Floyd's algorithm\n\n";
    int distances[max_vertices][max_vertices];

    solution(graph, distances);

    output_distances(distances);

    auto dur = chrono::steady_clock::now() - start;
    cout << "\ntime: " << chrono::duration_cast<chrono::milliseconds>(dur).count() << " mcs\n" << endl;
}

void solution(int graph[][max_vertices], int distances[][max_vertices]) {
    for (int i = 0; i < max_vertices; ++i) {
        for (int j = 0; j < max_vertices; ++j) {
            if (i != j && graph[i][j] == 0) {
                distances[i][j] = INF;
            } else {
                distances[i][j] = graph[i][j];
            }
        }
    }

    for (int k = 0; k < max_vertices; ++k) {
        for (int i = 0; i < max_vertices; ++i) {
            for (int j = 0; j < max_vertices; ++j) {
                if (distances[i][k] != INF && distances[k][j] != INF &&
                    distances[i][k] + distances[k][j] < distances[i][j]) {
                    distances[i][j] = distances[i][k] + distances[k][j];
                }
            }
        }
    }
}

void output_distances(int distances[][max_vertices]) {
    for (int i = 0; i < max_vertices; i++) {
        for (int j = 0; j < max_vertices; j++) {
            cout << setw(2) << distances[i][j] << " ";
        }
        cout << endl;
    }
}