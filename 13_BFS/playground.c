#include <stdio.h>

#define MAX 10

int graph[MAX][MAX], visited[MAX];
int queue[MAX], front = -1, rear = -1;
int n; // Number of vertices

// Enqueue function
void enqueue(int vertex) {
    if (rear == MAX - 1)
        printf("Queue overflow\n");
    else {
        if (front == -1)
            front = 0;
        queue[++rear] = vertex;
    }
}

// Dequeue function
int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    else
        return queue[front++];
}

// BFS function
void BFS(int start) {
    int i;
    enqueue(start);
    visited[start] = 1;

    while (front <= rear) {
        int current = dequeue();
        printf("%d ", current);

        for (i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
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

    printf("BFS Traversal starting from vertex %d:\n", start);
    BFS(start);

    return 0;
}
// Output will be the BFS traversal of the graph starting from the given vertex
// Example input:
// Enter number of vertices: 5
// Enter adjacency matrix:
// 0 1 0 1 0
// 1 0 1 0 1
// 0 1 0 0 0
// 1 0 0 0 1
// 0 1 0 1 0
// Enter starting vertex (0 to 4): 0
// BFS Traversal starting from vertex 0:
// 0 1 3 2 4
// This will traverse the graph in breadth-first order starting from vertex 0.
// The adjacency matrix represents the connections between vertices in the graph.
// The output will vary based on the input adjacency matrix and starting vertex.
// The BFS algorithm uses a queue to explore the graph level by level, visiting all neighbors of a vertex before moving on to the next level.
// The visited array keeps track of which vertices have already been visited to avoid cycles and redundant processing.
// The enqueue and dequeue functions manage the queue operations for BFS traversal.
// The BFS function starts from the given vertex, marks it as visited, and explores all its adjacent vertices, adding them to the queue for further exploration.
// The BFS algorithm is particularly useful for finding the shortest path in unweighted graphs and exploring all reachable vertices from a starting point.
// The BFS traversal ensures that all vertices at the current level are processed before moving on to the next level, making it suitable for scenarios where the shortest path or level-wise exploration is required.