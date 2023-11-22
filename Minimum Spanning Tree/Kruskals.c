#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_EDGES 100

// Structure to represent an edge in the graph
typedef struct {
    int src, dest, weight;
} Edge;

// Structure to represent a graph
typedef struct {
    int V, E; // V: number of vertices, E: number of edges
    Edge edges[MAX_EDGES]; // Array of edges
} Graph;

// Structure to represent a subset for union-find
typedef struct {
    int parent;
    int rank;
} Subset;

// Function to create a graph
Graph* createGraph(int V, int E) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    return graph;
}

// Comparison function for sorting edges based on their weights
int compareEdges(const void* a, const void* b) {
    Edge* edgeA = (Edge*)a;
    Edge* edgeB = (Edge*)b;
    return edgeA->weight - edgeB->weight;
}

// Function to find the set of an element using path compression
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

// Function to perform union of two sets using rank
void unionSets(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
  
    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    }
    else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    }
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Function to find the minimum spanning tree using Kruskal's algorithm
void kruskalMST(Graph* graph) {
    int V = graph->V;
    int E = graph->E;
    Edge result[V]; // Array to store the resulting minimum spanning tree
    int e = 0; // Index variable used for result[]
    int i = 0; // Index variable used for sorted edges
  
    // Step 1: Sort all the edges in non-decreasing order of their weights
    qsort(graph->edges, E, sizeof(Edge), compareEdges);
  
    // Allocate memory for creating V subsets
    Subset* subsets = (Subset*)malloc(V * sizeof(Subset));
  
    // Create V subsets with single elements
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
  
    // Step 2: Process E edges in sorted order of their weights
    while (e < V - 1 && i < E) {
        // Step 2a: Pick the smallest edge
        Edge nextEdge = graph->edges[i++];
  
        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);
  
        // Step 2b: If including this edge does not form a cycle, add it to the result and increment the index of the result
        if (x != y) {
            result[e++] = nextEdge;
            unionSets(subsets, x, y);
        }
    }
  
    // Print the constructed minimum spanning tree
    printf("Edge \tWeight\n");
    for (i = 0; i < e; i++) {
        printf("%d - %d \t%d\n", result[i].src, result[i].dest, result[i].weight);
    }
  
    free(subsets);
}

int main() {
    int V, E; // V: number of vertices, E: number of edges
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &V, &E);
  
    Graph* graph = createGraph(V, E);
  
    printf("Enter the source, destination, and weight of each edge:\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &graph->edges[i].src, &graph->edges[i].dest, &graph->edges[i].weight);
    }
  
    kruskalMST(graph);
  
    free(graph);
  
    return 0;
}


