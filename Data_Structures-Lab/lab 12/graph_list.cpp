//Program to implement a graph using adjacency list

#include <iostream>
using namespace std;
#define MAX_VERTICES 100

class Graph {
private:
struct Node {
    int dest;
    Node* next;
    };
    Node* adjList[MAX_VERTICES];
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
    (int src, int dest)
    int n;
    printf("Enter number of vertices in graph (max %d): ", MAX_VERTICES);
    scanf("%d", &n);

    if (n <= 0 || n > MAX_VERTICES) {
        printf("Invalid number of vertices. Exiting.\n");
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
                g.freeGraph();
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 5);

    return 0;
}

//Constructor
Graph::Graph() {
    int vertices;
    n = vertices;
    for (int i = 0; i < n; i++)
        adjList[i] = NULL;
}

//Function to check if the vertex is valid
bool Graph::isValidVertex(int v) {
    return v >= 0 && v < n;
}

//Function to insert an edge
void Graph::insertEdge() {
    (int src, int dest)
    if (!isValidVertex(src) || !isValidVertex(dest)) {
        printf("Invalid vertices.\n");
        return;
    }

    Node* newNode = new Node{dest, adjList[src]};
    adjList[src] = newNode;

    Node* newNode2 = new Node{src, adjList[dest]};
    adjList[dest] = newNode2;

    printf("Edge inserted.\n");
}

//Function to delete an edge
int Graph::deleteEdge(){
    (int src, int dest)
    if (!isValidVertex(src) || !isValidVertex(dest)) {
        printf("Invalid vertices.\n");
        return 0;
    }

    Node* curr = adjList[src];
    Node* prev = NULL;
    while (curr != NULL) {
        if (curr->dest == dest) {
            if (prev == NULL)
                adjList[src] = curr->next;
            else
                prev->next = curr->next;
            delete curr;
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    curr = adjList[dest];
    prev = NULL;
    while (curr != NULL) {
        if (curr->dest == src) {
            if (prev == NULL)
                adjList[dest] = curr->next;
            else
                prev->next = curr->next;
            delete curr;
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    printf("Edge deleted (if existed).\n");
    return 1;
}

//Function to search for an edge
int Graph::searchEdge() {
    (int src, int dest)
    if (!isValidVertex(src) || !isValidVertex(dest)) {
        printf("Invalid vertices.\n");
        return 0;
    }

    Node* curr = adjList[src];
    while (curr != NULL) {
        if (curr->dest == dest) {
            printf("Edge exists.\n");
            return 1;
        }
        curr = curr->next;
    }

    printf("Edge does not exist.\n");
    return 0;
}

//Function to display the graph
int Graph::displayGraph() {
    printf("Adjacency List of Graph:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        Node* curr = adjList[i];
        while (curr != NULL) {
            printf("%d ", curr->dest);
            curr = curr->next;
        }
        printf("\n");
    }
    return 1;
}
