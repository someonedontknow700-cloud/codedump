#include <stdio.h>

void kruskal(int n, int cost[20][20])
{
    int parent[20];

    for (int i = 0; i < 20; i++)
        parent[i] = -1;

    int ne = 1, mincost = 0;

    while (ne < n)
    {
        int a = -1, b = -1, u = -1, v = -1;
        int min = 999;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        if (min == 999)
        {
            printf("Graph is disconnected\n");
            return;
        }

        while (parent[u] != -1)
            u = parent[u];

        while (parent[v] != -1)
            v = parent[v];

        if (u != v)
        {
            printf("%d edge (%d,%d) = %d\n", ne++, a, b, min);
            mincost += min;
            parent[v] = u;
        }

        cost[a][b] = cost[b][a] = 999;
    }

    printf("\nMinimum cost = %d\n", mincost);
}

int main()
{
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int cost[20][20];

    printf("Enter cost matrix:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if (cost[i][j] == 0 || i == j)
                cost[i][j] = 999;
        }
    }

    kruskal(n, cost);

    return 0;
}