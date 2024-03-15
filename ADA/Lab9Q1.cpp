#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <utility>
#include <climits>

using namespace std;

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V;
    vector<vector<Edge>> adjList;

    Graph(int V) : V(V), adjList(V) {}

    void addEdge(int u, int v, int weight) {
        adjList[u].push_back({u, v, weight});
        adjList[v].push_back({v, u, weight});
    }
};

vector<Edge> primMST(Graph& graph) {
    vector<Edge> mst;
    vector<int> dist(graph.V, INT_MAX);
    vector<int> parent(graph.V, -1);
    vector<bool> inMST(graph.V, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int src = 0;
    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        for (auto& neighbor : graph.adjList[u]) {
            int v = neighbor.dest;
            int weight = neighbor.weight;

            if (!inMST[v] && weight < dist[v]) {
                dist[v] = weight;
                pq.push({dist[v], v});
                parent[v] = u;
            }
        }
    }

    for (int i = 1; i < graph.V; ++i) {
        mst.push_back({parent[i], i, dist[i]});
    }

    return mst;
}

int main() {
    int V = 5;
    Graph graph(V);

    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 3, 6);
    graph.addEdge(1, 2, 3);
    graph.addEdge(1, 3, 8);
    graph.addEdge(1, 4, 5);
    graph.addEdge(2, 4, 7);
    graph.addEdge(3, 4, 9);

    vector<Edge> minimum_spanning_tree = primMST(graph);

    cout << "Minimum Spanning Tree using Prim's algorithm:\n";
    for (auto& edge : minimum_spanning_tree) {
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
    }

    return 0;
}
