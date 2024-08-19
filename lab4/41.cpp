/*
[Option 6]
1. Write a program to find the shortest distances from the 1st vertex to
all others for a graph according to your option (see Fig. 11),
using Dijkstra's algorithm. Make a table
comparing the two algorithms by time or number of steps.
*/

#include <chrono>
#include <iomanip>
#include <iostream>
using namespace std;

const int count_vertices = 8;
const int INF = 1e9;

void solution(int graph[][count_vertices], int lvl_vertices, int distances[]);

int main() {
    //    1 2 3 4 5 6 7 8
    int graph[count_vertices][count_vertices] = {{0, 3, 0, 0, 0, 0, 0, 1}, {3, 0, 0, 3, 0, 0, 2, 2},
                                                 {0, 0, 0, 4, 0, 0, 3, 0}, {0, 2, 4, 0, 5, 7, 0, 0},
                                                 {0, 0, 0, 5, 0, 6, 0, 0}, {0, 0, 0, 7, 6, 0, 4, 5},
                                                 {0, 2, 3, 0, 0, 4, 0, 1}, {1, 2, 0, 0, 0, 5, 1, 0}};

    int distances[count_vertices];
    cout << "\n[Task 1 - Dijkstra's algorithm] \n\n";

    auto start = chrono::steady_clock::now();
    for (int lvl_vertices = 0; lvl_vertices < count_vertices; lvl_vertices++) {
        solution(graph, lvl_vertices, distances);

        for (int i = 0; i < count_vertices; ++i) {
            cout << setw(2) << distances[i] << " ";
        }
        cout << endl;
    }

    auto dur = chrono::steady_clock::now() - start;
    cout << "\ntime: " << chrono::duration_cast<chrono::milliseconds>(dur).count() << " mcs\n" << endl;
}

void solution(int graph[][count_vertices], int lvl_vertices, int distances[]) {
    bool visited[count_vertices] = {false};

    for (int i = 0; i < count_vertices; ++i) {
        distances[i] = INF;
    }
    distances[lvl_vertices] = 0;

    for (int i = 0; i < count_vertices; ++i) {
        int min_distance = INF;
        int index;

        for (int j = 0; j < count_vertices; ++j) {
            if (!visited[j] && distances[j] < min_distance) {
                min_distance = distances[j];
                index = j;
            }
        }

        visited[index] = true;

        for (int i = 0; i < count_vertices; ++i) {
            if (!visited[i] && graph[index][i] != 0 && distances[index] != INF &&
                distances[index] + graph[index][i] < distances[i]) {
                distances[i] = distances[index] + graph[index][i];
            }
        }
    }
}
