#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w) {}
};

void topologicalSortUtil(int node, vector<bool>& visited, stack<int>& sortedOrder, vector<vector<Edge>>& graph) {
    visited[node] = true;
    for (Edge& edge : graph[node]) {
        if (!visited[edge.to]) {
            topologicalSortUtil(edge.to, visited, sortedOrder, graph);
        }
    }
    sortedOrder.push(node);
}

vector<int> shortestPathDAG(int source, int vertices, vector<vector<Edge>>& graph) {

    stack<int> sortedOrder;
    vector<bool> visited(vertices, false);
    for (int i = 0; i < vertices; ++i) {
        if (!visited[i]) {
            topologicalSortUtil(i, visited, sortedOrder, graph);
        }
    }

    vector<int> distance(vertices, INF);
    distance[source] = 0;

    while (!sortedOrder.empty()) {
        int node = sortedOrder.top();
        sortedOrder.pop();
        if (distance[node] != INF) {
            for (Edge& edge : graph[node]) {
                if (distance[edge.to] > distance[node] + edge.weight) {
                    distance[edge.to] = distance[node] + edge.weight;
                }
            }
        }
    }

    return distance;
}

int main() {
    int vertices = 6;
    vector<vector<Edge>> graph(vertices);

    graph[0].push_back(Edge(1, 5));
    graph[0].push_back(Edge(2, 3));
    graph[1].push_back(Edge(3, 6));
    graph[1].push_back(Edge(2, 2));
    graph[2].push_back(Edge(4, 4));
    graph[2].push_back(Edge(5, 2));
    graph[3].push_back(Edge(4, 6));
    graph[4].push_back(Edge(5, 1));

    int source = 0;
    vector<int> shortestDistances = shortestPathDAG(source, vertices, graph);

    cout << "Shortest distances from source vertex " << source << " to all other vertices:" << endl;
    for (int i = 0; i < vertices; ++i) {
        cout << "Vertex " << i << ": ";
        if (shortestDistances[i] == INF) {
            cout << "Infinity" << endl;
        } else {
            cout << shortestDistances[i] << endl;
        }
    }

    return 0;
}
