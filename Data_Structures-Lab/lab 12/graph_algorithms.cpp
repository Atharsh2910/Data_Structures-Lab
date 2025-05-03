//Program to implement Kruskal's algorithm, Prim's algorithm, and Dijkstra's algorithm
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>

#define MAX_DIST 1000000

using namespace std;

class Graph {
private:
    struct Edge {
        int src, dest, weight;
        Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
    };

    int V;
    vector<vector<pair<int, int>>> adjList;
    vector<Edge> edges;

public:
    Graph(int vertices);
    void addEdge();
    void display();
    void prims();
    int findParent();
    void kruskal();
    void dijkstra();
};

int main() {
    int u, vector<int> &parent
    int u, int v, int w
    int V, choice;
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    Graph g(V);

    while (1) {
        printf("\nMenu:\n"
               "1. Add Edge\n"
               "2. Display Graph\n"
               "3. Prim’s Algorithm\n"
               "4. Kruskal’s Algorithm\n"
               "5. Dijkstra’s Algorithm\n"
               "6. Exit\n"
               "Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int u, v, w;
            printf("Enter source, destination, weight: ");
            scanf("%d %d %d", &u, &v, &w);
            g.addEdge(u, v, w);
        } else if (choice == 2) {
            g.display();
        } else if (choice == 3) {
            g.prims();
        } else if (choice == 4) {
            g.kruskal();
        } else if (choice == 5) {
            int src;
            printf("Enter source vertex: ");
            scanf("%d", &src);
            g.dijkstra(src);
        } else if (choice == 6) {
            break;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

//Constructor
Graph::Graph() {
    V = vertices;
    adjList.resize(V);
}

//Function to add an edge to the graph
void Graph::addEdge() {
    int u, int v, int w
    adjList[u].emplace_back(v, w);
    adjList[v].emplace_back(u, w);
    edges.emplace_back(u, v, w);
}

//Function to display the graph
void Graph::display() {
    printf("\nGraph Adjacency List:\n");
    for (int i = 0; i < V; ++i) {
        printf("%d -> ", i);
        for (auto &p : adjList[i]) {
            printf("(%d, %d) ", p.first, p.second);
        }
        printf("\n");
    }
}

//Function to implement Prim's algorithm
void Graph::prims() {
    vector<int> key(V, MAX_DIST), parent(V, -1);
    vector<bool> inMST(V, false);
    key[0] = 0;

    for (int count = 0; count < V - 1; ++count) {
        int u = -1;
        for (int i = 0; i < V; ++i)
            if (!inMST[i] && (u == -1 || key[i] < key[u]))
                u = i;

        if (u == -1) {
            printf("The graph is disconnected!\n");
            return;
        }

        inMST[u] = true;

        for (auto &pair : adjList[u]) {
            int v = pair.first, w = pair.second;
            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
            }
        }
    }

    printf("Minimum Spanning Tree (Prim's):\n");
    for (int i = 1; i < V; ++i)
        printf("%d - %d (Weight: %d)\n", parent[i], i, key[i]);
}

//Function to find the parent of a vertex
int Graph::findParent(int u, vector<int> &parent) {
    int u, vector<int> &parent
    if (parent[u] != u)
        parent[u] = findParent(parent[u], parent);
    return parent[u];
}


//Function to implement Kruskal's algorithm
void Graph::kruskal() {
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    vector<int> parent(V);
    for (int i = 0; i < V; ++i)
        parent[i] = i;

    printf("Minimum Spanning Tree (Kruskal's):\n");
    for (auto &e : edges) {
        int pu = findParent(e.src, parent);
        int pv = findParent(e.dest, parent);
        if (pu != pv) {
            printf("%d - %d (Weight: %d)\n", e.src, e.dest, e.weight);
            parent[pu] = pv;
        }
    }
}


//Function to implement Dijkstra's algorithm
void Graph::dijkstra(]) {
    int src
    vector<int> dist(V, MAX_DIST);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, src);

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto &pair : adjList[u]) {
            int v = pair.first;
            int w = pair.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }

    printf("Shortest paths from source %d:\n", src);
    for (int i = 0; i < V; ++i) {
        if (dist[i] == MAX_DIST)
            printf("No path to %d\n", i);
        else
            printf("Distance to %d = %d\n", i, dist[i]);
    }
}