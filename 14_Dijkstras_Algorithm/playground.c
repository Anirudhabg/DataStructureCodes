// From a given vertex in a weighted connected graph, find shortest paths to other vertices Using Dijkstra's algorithm (C programming)

#include <stdio.h>
int COST[20][20], PATH[10], Visited[10], DISTANCE[10], n;

void dijikstrasAlgorithm(int SOURCE)
{
    int count = 1, u, minimum;
    for (int i = 0; i < n; i++)
    {
        Visited[i] = 0;
        PATH[i] = SOURCE;
        DISTANCE[i] = COST[SOURCE][i];
    }

    Visited[SOURCE] = 1;
    while (count < n)
    {
        u = -1;
        minimum = 99;
        for (int i = 0; i < n; i++)
        {
            if (Visited[i] == 0 && DISTANCE[i] < minimum)
            {
                minimum = DISTANCE[i];
                u = i;
            }
        }
        Visited[u] = 1;
        for (int i = 0; i < n; i++)
        {
            if (Visited[i] == 0 && DISTANCE[u] + COST[u][i] < DISTANCE[i])
            {
                DISTANCE[i] = DISTANCE[u] + COST[u][i];
                PATH[i] = u;
            }
        }
        count++;
    }
}

void printPath(int SOURCE, int DESTINATION)
{
    int i = DESTINATION;

    while (i != SOURCE)
    {
        printf("%d <-- ", i);
        i = PATH[i];
    }
    printf("%d == %d\n", i, DISTANCE[DESTINATION]);
}

void main()
{
    int SOURCE;
    printf("\n Enter the size of the matrix: ");
    scanf("%d", &n);

    printf("\n Enter the adjacency matrix of the undirected graph only: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &COST[i][j]);
        }
    }

    printf("\n Cost Adjacency Matrix is: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf(" %d ", COST[i][j]);
        }
        printf("\n");
    }

    printf("\n Enter the source: ");
    scanf("%d", &SOURCE);

    dijikstrasAlgorithm(SOURCE);
    for (int k = 0; k < n; k++)
    {
        printPath(SOURCE, k);
    }
}