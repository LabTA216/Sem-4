#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {    
    int src, dest, weight;
};

struct Graph {
    int V, E;
    vector<Edge> edges;
};


struct Subset {
    int parent, rank;
};

int find(vector<Subset>& subsets, int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(vector<Subset>& subsets, int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

bool comparator(const Edge& e1, const Edge& e2) {
    return e1.weight < e2.weight;
}

vector<Edge> kruskalMST(Graph& graph) {
    int V = graph.V;
    vector<Edge> result;
    int e = 0;
    int i = 0;
    vector<Subset> subsets(V);

    sort(graph.edges.begin(), graph.edges.end(), comparator);

    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < graph.E) {
        Edge next_edge = graph.edges[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y) {
            result.push_back(next_edge);
            Union(subsets, x, y);
            e++;
        }
    }

    return result;
}

int main() {
    int V = 4;
    int E = 5; 

    Graph graph;
    graph.V = V;
    graph.E = E;
    graph.edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    vector<Edge> minimum_spanning_tree = kruskalMST(graph);

    cout << "Minimum Spanning Tree using Kruskal's algorithm:\n";
    for (auto& edge : minimum_spanning_tree) {
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
    }

    return 0;
}
