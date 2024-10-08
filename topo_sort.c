#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Structure to represent a node in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Structure to represent the adjacency list
struct Graph {
    struct Node* head[MAX_NODES];
};

// Function to create a new node
struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with 'vertices' nodes
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    for (int i = 0; i < vertices; ++i) {
        graph->head[i] = NULL;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->head[src];
    graph->head[src] = newNode;
}

// DFS recursive function for topological sorting
void topologicalSortUtil(struct Graph* graph, int v, int visited[], int stack[], int* stackIndex) {
    visited[v] = 1; // Mark the current node as visited

    struct Node* temp = graph->head[v];
    while (temp != NULL) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex]) {
            topologicalSortUtil(graph, adjVertex, visited, stack, stackIndex);
        }
        temp = temp->next;
    }

    // After visiting all adjacent vertices of a vertex, push it to the stack
    stack[(*stackIndex)++] = v;
}

// Function to perform Topological Sort using DFS
void topologicalSort(struct Graph* graph, int vertices) {
    int visited[MAX_NODES] = {0};
    int stack[MAX_NODES];
    int stackIndex = 0;

    for (int i = 0; i < vertices; ++i) {
        if (!visited[i]) {
            topologicalSortUtil(graph, i, visited, stack, &stackIndex);
        }
    }

    // Print contents of the stack (which represents the topological order)
    printf("Topological Sorting: ");
    while (stackIndex > 0) {
        printf("%d ", stack[--stackIndex]+1);
    }
}

int main() {
    int vertices, edges;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d",&vertices, &edges);
    struct Graph* graph = createGraph(vertices);
   
    printf("Add edges to the graph (format: from to): \n");
    int a,b;
    for(int i = 0; i < edges; i++)
    {
    scanf("%d %d",&a,&b);
    addEdge(graph, a-1, b-1);
    }

    topologicalSort(graph, vertices);

    return 0;
}