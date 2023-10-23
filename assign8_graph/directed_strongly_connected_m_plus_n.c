#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 1000

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node* adjLists[MAX_VERTICES];
    int visited[MAX_VERTICES];
    int stack[MAX_VERTICES];
    int stackTop;
};

struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    graph->stackTop = -1;

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

void DFS(struct Graph* graph, int vertex) {
    graph->visited[vertex] = 1;

    struct Node* temp = graph->adjLists[vertex];
    while (temp != NULL) {
        int adjVertex = temp->vertex;
        if (!graph->visited[adjVertex]) {
            DFS(graph, adjVertex);
        }
        temp = temp->next;
    }

    graph->stack[++graph->stackTop] = vertex;
}

int isStronglyConnected(struct Graph* graph) {
    // Perform DFS on the original graph
    DFS(graph, 0);

    // Check if all vertices are visited
    for (int i = 0; i < graph->numVertices; i++) {
        if (!graph->visited[i]) {
            return 0; // Graph is not strongly connected
        }
    }

    // Reset visited array for the second DFS
    for (int i = 0; i < graph->numVertices; i++) {
        graph->visited[i] = 0;
    }

    // Transpose the graph
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjLists[i];
        while (temp != NULL) {
            int adjVertex = temp->vertex;
            addEdge(graph, adjVertex, i);
            temp = temp->next;
        }
    }

    // Perform DFS on the transposed graph
    DFS(graph, 0);

    // Check if all vertices are visited
    for (int i = 0; i < graph->numVertices; i++) {
        if (!graph->visited[i]) {
            return 0; // Graph is not strongly connected
        }
    }

    return 1; // Graph is strongly connected
}

int main() {
    struct Graph* graph = createGraph(5);

    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 2);

    int isConnected = isStronglyConnected(graph);

    if (isConnected) {
        printf("The graph is strongly connected.\n");
    } else {
        printf("The graph is not strongly connected.\n");
    }

    return 0;
}