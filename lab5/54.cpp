// Прим


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;
struct Edge {
    int vertex, weight;
};
int main() {
    int V = 8;
    setlocale(0, "");
    vector<vector<Edge>> adj(V);
    // Заполнение графа
    adj[0] = { {1, 8}, {6, 9} };
    adj[1] = { {0, 8}, {2, 2}, {4, 5} };
    adj[2] = { {1, 2}, {3, 3}, {5, 10} };
    adj[3] = { {2, 3}, {5, 3} };
    adj[4] = { {1, 5}, {5, 6}, {6, 9} };
    adj[5] = { {2, 10}, {3, 3}, {4, 6}, {7, 12} };
    adj[6] = { {0, 9}, {4, 9}, {7, 7} };
    adj[7] = { {5, 12}, {6, 7} };




    vector<int> cost(V, INF);   
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false); 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    
    
    int start = 0;
    pq.push({ 0, start });
    cost[start] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        inMST[u] = true;
        for (Edge& edge : adj[u]) {
            int v = edge.vertex;
            int w = edge.weight;
            if (!inMST[v] && cost[v] > w) {
                cost[v] = w;
                pq.push({ w, v });
                parent[v] = u;
            }
        }
    }


    // Вывод результата
    for (int i = 1; i < V; ++i)
        if (parent[i] != -1)
            cout << "Vertex " << parent[i] << " contacts the top " << i << "edge weight " << cost[i] << endl;

}