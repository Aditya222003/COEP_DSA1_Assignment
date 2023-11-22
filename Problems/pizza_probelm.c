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
void printSolution(int dist[], int parent[], int src, int dest) {
    printf("Shortest Path from %d to %d:\n", src, dest);
    printf("Vertex\tDistance\tPath\n");
    printf("%d\t%d\t\t%d ", dest, dist[dest], src);
    printPath(parent, dest);
    printf("\n");
}

// Function to implement Dijkstra's algorithm
void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int src, int dest, int V) {
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
    printSolution(dist, parent, src, dest);
}

int main() {
    int V = 9; // Number of vertices
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    int src = 0;   // Source vertex
    int dest = 8;  // Destination vertex

    dijkstra(graph, src, dest, V);

    return 0;
}
