#include <stdio.h>

#define MAX 10

int graph[MAX][MAX], visited[MAX];
int n; // Number of vertices

// DFS function
void DFS(int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    // Initialize all vertices as unvisited
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("DFS Traversal starting from vertex %d:\n", start);
    DFS(start);

    return 0;
}
// Output will be the DFS traversal of the graph starting from the given vertex
// Example input:
// Enter number of vertices: 5
// Enter adjacency matrix:
// 0 1 0 1 0
// 1 0 1 0 1
// 0 1 0 0 0
// 1 0 0 0 1
// 0 1 0 1 0
// Enter starting vertex (0 to 4): 0
// DFS Traversal starting from vertex 0:
// 0 1 2 3 4
// This will traverse the graph in depth-first order starting from vertex 0.
// The adjacency matrix represents the connections between vertices in the graph.
// The output will vary based on the input adjacency matrix and starting vertex.
// The DFS function marks the current vertex as visited and recursively visits all its adjacent vertices that have not been visited yet.
// The visited array keeps track of which vertices have been visited to avoid cycles.
// The program will print the order of vertices visited during the DFS traversal.
