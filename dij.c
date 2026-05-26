#include <stdio.h>

#define INF 999

void dij(int n, int a[10][10], int source)
{
    int d[10], s[10], u;

    for (int i = 0; i < n; i++)
    {
        s[i] = 0;
        d[i] = a[source][i];
    }

    d[source] = 0;
    s[source] = 1;

    for (int i = 0; i < n - 1; i++)
    {
        int min = INF;

        for (int j = 0; j < n; j++)
        {
            if (s[j] == 0 && d[j] < min)
            {
                min = d[j];
                u = j;
            }
        }

        s[u] = 1;

        for (int k = 0; k < n; k++)
        {
            if (s[k] == 0 &&
                a[u][k] != INF &&
                d[u] + a[u][k] < d[k])
            {
                d[k] = d[u] + a[u][k];
            }
        }
    }

    printf("\nShortest distances:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d -> %d = %d\n", source, i, d[i]);
    }
}

int main()
{
    int n;

    scanf("%d", &n);

    int a[10][10];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    int source;

    scanf("%d", &source);

    dij(n, a, source);

    return 0;
}