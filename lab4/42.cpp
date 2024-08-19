/*
[Option 6]
2. Olya (A), Masha (B), Vitya (C), Dima (D), Vanya (E) and Katya (F) live in
different cities. The cost of tickets from different cities is known (Fig. 10).
There are different ways to get to the cities. Determine
the smallest amount that needs to be spent so that Olya can
visit each of her friends.
*/

#include <chrono>
#include <iomanip>
#include <iostream>
using namespace std;

const int max_vertices = 6;
const int INF = 1e9;

void solution(int graph[][max_vertices], int distances[][max_vertices]);
void output_distances(int distances[][max_vertices]);
int all_city_min_cost(int distances[][max_vertices]);

int main() {
    // A B C D E F
    int graph[max_vertices][max_vertices] = {{0, 0, 0, 5, 6, 9}, {0, 0, 7, 8, 5, 8}, {0, 7, 0, 4, 5, 4},
                                             {5, 8, 4, 0, 0, 0}, {6, 5, 5, 0, 0, 0}, {9, 8, 4, 0, 0, 0}};

    int distances[max_vertices][max_vertices];

    cout << "\n[Task 2]\n\n";
    solution(graph, distances);

    output_distances(distances);

    int res = all_city_min_cost(distances);
    cout << "\nMin cost: " << res << endl << endl;
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

int all_city_min_cost(int distances[][max_vertices]) {
    int min_cost = 0;

    bool visited[max_vertices] = {false};
    visited[0] = true;

    int current_city = 0;

    for (int i = 1; i < max_vertices; ++i) {
        int next_city;
        int min_distance = INF;

        for (int j = 0; j < max_vertices; ++j) {
            if (!visited[j] && distances[current_city][j] < min_distance) {
                next_city = j;
                min_distance = distances[current_city][j];
            }
        }

        visited[next_city] = true;
        min_cost += min_distance;
        current_city = next_city;
    }
    return min_cost;
}