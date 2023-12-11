//Метод Крускала

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};


// Сравнение рёбер по весу для сортировки
bool compareEdges(Edge e1, Edge e2) {
    return e1.weight < e2.weight;
}


// Найти множество вершины
int findSet(int v, vector<int>& parent) {
    if (v == parent[v])
        return v;
    return parent[v] = findSet(parent[v], parent);
}


// Объединить два множества
void unionSets(int a, int b, vector<int>& parent, vector<int>& rank) {
    a = findSet(a, parent);
    b = findSet(b, parent);
    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}



// Метод Крускала для поиска MST
void kruskal(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), compareEdges);
    vector<int> parent(V);
    vector<int> rank(V, 0);
    for (int i = 0; i < V; i++)
        parent[i] = i;
    vector<Edge> result;
    for (Edge e : edges) {
        if (findSet(e.src, parent) != findSet(e.dest, parent)) {
            result.push_back(e);
            unionSets(e.src, e.dest, parent, rank);
        }
    }
    
    for (Edge e : result) {
        cout << "vertex " << e.src << " contacts the top " << e.dest << " edge weight " << e.weight << endl;
    }
}



int main() {
    int V = 8;
    setlocale(0, "");
    vector<Edge> edges = {
        {0, 1, 8}, {0, 6, 9}, {1, 2, 2}, {1, 4, 5}, {2, 3, 3},
        {2, 5, 10}, {3, 5, 3}, {4, 5, 6}, {4, 6, 9}, {5, 7, 12}, {6, 7, 7}
    };
    kruskal(V, edges);

}