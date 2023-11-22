#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 100
#define INF INT_MAX

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], bool sptSet[], int V) {
    int min = INF;
    int minIndex;

    for (int v = 0; v < V; v++) {
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }

    return minIndex;
}

// Function to print the shortest path from source to destination
void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        printf("%d ", j);
        return;
    }

    printPath(parent, parent[j]);
    printf("%d ", j);
}

// Function to print the distance array
void printSolution(int dist[], int parent[], int src, int V) {
    printf("Vertex\tDistance\tPath");
    for (int i = 0; i < V; i++) {
        printf("\n%d\t%d\t\t%d ", i, dist[i], src);
        printPath(parent, i);
    }
    printf("\n");
}

// Function to implement Dijkstra's algorithm
void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int src, int V) {
    int dist[MAX_VERTICES];     // Array to store the shortest distance from the source
    bool sptSet[MAX_VERTICES];  // Set to represent vertices included in the shortest path tree
    int parent[MAX_VERTICES];   // Array to store the parent of each vertex in the shortest path tree

    // Initialize all distances as infinite and sptSet as false
    for (int v = 0; v < V; v++) {
        dist[v] = INF;
        sptSet[v] = false;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;
    parent[src] = -1;

    // Find the shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print the solution
    printSolution(dist, parent, src, V);
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

    int src;
    printf("Enter the source vertex: ");
    scanf("%d", &src);

    dijkstra(graph, src, V);

    return 0;
}
