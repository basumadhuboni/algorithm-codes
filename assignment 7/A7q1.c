#include <stdio.h>
#include <stdlib.h>

// Define a structure for an edge
struct Edge {
    int destination;
    struct Edge* next;
};

// Define a structure for a vertex
struct Vertex {
    struct Edge* head;
};

// Function to add an edge to an adjacency list
void addEdge(struct Vertex* vertices, int source, int destination) {
    struct Edge* newEdge = (struct Edge*)malloc(sizeof(struct Edge));
    newEdge->destination = destination;
    newEdge->next = vertices[source].head;
    vertices[source].head = newEdge;

    // Assuming the graph is undirected, add the edge in reverse as well
    newEdge = (struct Edge*)malloc(sizeof(struct Edge));
    newEdge->destination = source;
    newEdge->next = vertices[destination].head;
    vertices[destination].head = newEdge;
}

int main() {
    int n, m;
    printf("Enter the number of nodes (n) and edges (m): ");
    scanf("%d %d", &n, &m);

    // Create an array of vertices
    struct Vertex vertices[n];
    // Initialize vertices
    for (int i = 0; i < n; i++) {
        vertices[i].head = NULL;
    }

    // Take input for edges
    printf("Enter the edges (source destination):\n");
    for (int i = 0; i < m; i++) {
        int source, destination;
        scanf("%d %d", &source, &destination);
        addEdge(vertices, source, destination);
    }

    // Print the adjacency list (for verification)
    printf("Adjacency List:\n");
    for (int i = 0; i < n; i++) {
        struct Edge* current = vertices[i].head;
        printf("Vertex %d: ", i);
        while (current != NULL) {
            printf("%d -> ", current->destination);
            current = current->next;
        }
        printf("NULL\n");
    }

    return 0;
}