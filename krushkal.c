#include <stdio.h>

void kruskal(int n, int cost[20][20])
{
    int parent[20];

    for (int i = 0; i < 20; i++)
        parent[i] = -1;

    int ne = 1, mincost = 0;
    while (ne < n)
    {
        int a, b, u, v;
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

        while (parent[u] != -1)
            u = parent[u];
        while (parent[v] != -1)
            v = parent[v];

        if (u != v)
        {
            printf("%d edge (%d, %d) = %d\n", ne++, a, b, min);
            mincost += min;
            parent[v] = u;
        }

        cost[a][b] = cost[b][a] = 999;
    }

    printf("\nmincost: %d", mincost);
}

int main()
{
    int n;
    scanf("%d", &n);

    int cost[20][20];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
            {
                cost[i][j] = 999;
            }
        }
    }

    kruskal(n, cost);
}
