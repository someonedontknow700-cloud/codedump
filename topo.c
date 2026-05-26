#include <stdio.h>

int stack[10], top = -1;

/* ---------- DFS TOPO ---------- */

void dfs(int n, int a[10][10], int source, int v[])
{
    v[source] = 1;

    for (int i = 0; i < n; i++)
    {
        if (a[source][i] == 1 && !v[i])
        {
            dfs(n, a, i, v);
        }
    }

    stack[++top] = source;
}

void topoDFS(int n, int a[10][10])
{
    int v[10];

    for (int i = 0; i < n; i++)
        v[i] = 0;

    top = -1;

    for (int i = 0; i < n; i++)
    {
        if (!v[i])
        {
            dfs(n, a, i, v);
        }
    }

    printf("\nTopological Order (DFS):\n");

    while (top != -1)
    {
        printf("%d ", stack[top--]);
    }

    printf("\n");
}

/* ---------- SOURCE REMOVAL ---------- */

void topoSource(int n, int a[10][10])
{
    int sc[10] = {0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 1)
                sc[j]++;
        }
    }

    printf("\nTopological Order (Source Removal):\n");

    for (int i = 0; i < n; i++)
    {
        if (sc[i] == 0)
        {
            printf("%d ", i);

            sc[i] = -1;

            for (int j = 0; j < n; j++)
            {
                if (a[i][j] == 1)
                {
                    sc[j]--;
                }
            }

            i = -1;
        }
    }

    printf("\n");
}

/* ---------- MAIN ---------- */

int main()
{
    int n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int a[10][10];

    printf("Enter adjacency matrix:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    int choice;

    do
    {
        printf("\nMENU\n");
        printf("1. Topological Sort using DFS\n");
        printf("2. Topological Sort using Source Removal\n");
        printf("3. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            topoDFS(n, a);
            break;

        case 2:
            topoSource(n, a);
            break;

        case 3:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid Choice\n");
        }

    } while (choice != 3);

    return 0;
}