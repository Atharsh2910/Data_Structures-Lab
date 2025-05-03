//Program to implement a graph using an adjacency matrix

#include <iostream>
using namespace std;
#define MAX_VERTICES 100

class Graph {
private:
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int n;

    bool isValidVertex(int v);

public:
    Graph();
    void insertEdge();
    int deleteEdge();
    int searchEdge();
    int displayGraph();
};


int main() {
    int src, int dest
    int n;
    printf("Enter the number of vertices in the graph (max %d): ", MAX_VERTICES);
    scanf("%d", &n);

    if (n <= 0 || n > MAX_VERTICES) {
        printf("Invalid number of vertices. Program exiting.\n");
        return 0;
    }

    Graph g(n);
    int choice, src, dest;

    do {
        printf("\nGraph Menu:\n");
        printf("1. Insert Edge\n");
        printf("2. Delete Edge\n");
        printf("3. Search Edge\n");
        printf("4. Display Graph\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter source and destination vertices (0 to %d): ", n - 1);
                scanf("%d %d", &src, &dest);
                g.insertEdge(src, dest);
                break;
            case 2:
                printf("Enter source and destination vertices (0 to %d): ", n - 1);
                scanf("%d %d", &src, &dest);
                g.deleteEdge(src, dest);
                break;
            case 3:
                printf("Enter source and destination vertices (0 to %d): ", n - 1);
                scanf("%d %d", &src, &dest);
                g.searchEdge(src, dest);
                break;
            case 4:
                g.displayGraph();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

//Constructor
Graph::Graph() {
    int vertices;
    n = vertices;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adjMatrix[i][j] = 0;
}

//Function to check if the vertex is valid
bool Graph::isValidVertex(int v) {
    return v >= 0 && v < n;
}

//Function to insert an edge
void Graph::insertEdge(int src, int dest) {
    (int src, int dest)
    if (isValidVertex(src) && isValidVertex(dest)) {
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1;
        printf("Edge inserted between %d and %d.\n", src, dest);
    } else {
        printf("Invalid vertex number(s).\n");
    }
}

//Function to delete an edge
int Graph::deleteEdge(int src, int dest) {
    (int src, int dest)
    if (isValidVertex(src) && isValidVertex(dest)) {
        adjMatrix[src][dest] = 0;
        adjMatrix[dest][src] = 0;
        printf("Edge deleted between %d and %d.\n", src, dest);
        return 1;
    } else {
        printf("Invalid vertex number(s).\n");
        return 0;
    }
}

//Function to search for an edge
int Graph::searchEdge(int src, int dest) {
    (int src, int dest)
    if (isValidVertex(src) && isValidVertex(dest)) {
        if (adjMatrix[src][dest] == 1) {
            printf("Edge exists between %d and %d.\n", src, dest);
            return 1;
        } else {
            printf("Edge does NOT exist between %d and %d.\n", src, dest);
            return 0;
        }
    } else {
        printf("Invalid vertex number(s).\n");
        return 0;
    }
}

//Function to display the graph
int Graph::displayGraph() {
    if (n <= 0) {
        printf("Graph is empty.\n");
        return 0;
    }

    printf("Adjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
    return 1;
}
