#include <stdio.h>
#include <limits.h>

int COST[10][10], v1, v2, n;

void findMinimum()
{
    int minimum = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (COST[i][j] > 0 && COST[i][j] < minimum)
            {
                minimum = COST[i][j];
                v1 = i;
                v2 = j;
            }
        }
    }
}

void doUnion(int root[])
{
    int temp = root[v2];
    for (int i = 0; i < n; i++)
    {
        if (root[i] == temp)
        {
            root[i] = root[v1];
        }
    }
}

void kruskalAlgorithm()
{
    int root[50], count = 0, minimumCost = 0, minimum;

    for (int i = 0; i < n; i++)
    {
        root[i] = i;
    }

    while (count < n - 1)
    {
        findMinimum();
        minimum = COST[v1][v2];
        COST[v1][v2] = COST[v2][v1] = 0;

        if (root[v1] != root[v2])
        {
            printf("\n Connect (%d, %d)", v1, v2);
            doUnion(root);
            minimumCost += minimum;
            count++;
        }
    }

    printf("\n Minimum cost is: %d\n", minimumCost);
}

int main()
{
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

    kruskalAlgorithm();

    return 0;
}

