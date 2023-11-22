#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 100
#define INF INT_MAX

// Function to find the vertex with minimum key value
int findMinKey(int key[], bool mstSet[], int V) {
    int minKey = INF;
    int minIndex;
  
    for (int v = 0; v < V; v++) {
        if (mstSet[v] == false && key[v] < minKey) {
            minKey = key[v];
            minIndex = v;
        }
    }
  
    return minIndex;
}

// Function to print the minimum spanning tree
void printMST(int parent[], int graph[MAX_VERTICES][MAX_VERTICES], int V) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

// Function to implement Prim's algorithm
void primMST(int graph[MAX_VERTICES][MAX_VERTICES], int V) {
    int parent[MAX_VERTICES]; // Array to store constructed MST
    int key[MAX_VERTICES]; // Key values used to pick minimum weight edge
    bool mstSet[MAX_VERTICES]; // Set to represent vertices included in MST
  
    // Initialize all keys as infinite and not included in MST
    for (int i = 0; i < V; i++) {
        key[i] = INF;
        mstSet[i] = false;
    }
  
    // Always include the first vertex in MST
    key[0] = 0;
    parent[0] = -1; // First node is always the root of MST
  
    // Construct MST with V-1 vertices
    for (int count = 0; count < V - 1; count++) {
        // Find the vertex with the minimum key value from the set of vertices not yet included in MST
        int u = findMinKey(key, mstSet, V);
  
        // Add the selected vertex to the MST set
        mstSet[u] = true;
  
        // Update key values and parent index of the adjacent vertices of the selected vertex
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
  
    // Print the constructed MST
    printMST(parent, graph, V);
}

int main() {
    int V, E; // V: number of vertices, E: number of edges
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &V, &E);
  
    int graph[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix representation of the graph
    memset(graph, 0, sizeof(graph));
  
    printf("Enter the source, destination, and weight of each edge:\n");
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        graph[src][dest] = weight;
        graph[dest][src] = weight;
    }
  
    primMST(graph, V);
  
    return 0;
}
