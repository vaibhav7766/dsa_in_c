#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10

// Structure to represent a node in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Structure to represent the adjacency list of a vertex
struct List {
    struct Node* head;
};

// Structure to represent the graph
struct Graph {
    int numVertices;
    struct List* array;
};

// Function to create a new graph with a given number of vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    graph->array = (struct List*)malloc((numVertices + 1) * sizeof(struct List));

    for (int i = 0; i <= numVertices; i++) {
        graph->array[i].head = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = dest;
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

// Function to perform BFS traversal of the graph
void BFS(struct Graph* graph, int startVertex) {
    bool* visited = (bool*)malloc((graph->numVertices + 1) * sizeof(bool));

    for (int i = 0; i <= graph->numVertices; i++) {
        visited[i] = false;
    }

    int queue[MAX_VERTICES];
    int front = -1, rear = -1;

    visited[startVertex] = true;
    queue[++rear] = startVertex;

    while (front != rear) {
        int currentVertex = queue[++front];
        printf("%d ", currentVertex);

        struct Node* temp = graph->array[currentVertex].head;
        while (temp) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                queue[++rear] = adjVertex;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int numVertices = 6;
    struct Graph* graph = createGraph(numVertices);

    addEdge(graph, 1, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 5);
    addEdge(graph, 5, 3);
    addEdge(graph, 5, 6);
    addEdge(graph, 6, 4);

    printf("Breadth-First Search (BFS):\n");
    BFS(graph, 4);
    
    return 0;
}