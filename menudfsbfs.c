#include <stdio.h>

int count = 0;

void dfs(int n, int a[10][10], int source, int v[])
{
    printf("%d ", source);
    v[source] = 1;

    for (int i = 0; i < n; i++)
    {
        count++;

        if (!v[i] && a[source][i])
        {
            dfs(n, a, i, v);
        }
    }
}

void bfs(int n, int a[10][10], int source, int v[])
{
    int q[10];
    int f = 0, r = 0;

    v[source] = 1;
    q[r++] = source;

    while (f < r)
    {
        int u = q[f++];

        printf("%d ", u);

        for (int i = 0; i < n; i++)
        {
            count++;

            if (!v[i] && a[u][i])
            {
                q[r++] = i;
                v[i] = 1;
            }
        }
    }
}

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

    int source;

    printf("Enter source vertex: ");
    scanf("%d", &source);

    int choice;

    do
    {
        int v[10];

        for (int i = 0; i < n; i++)
            v[i] = 0;

        count = 0;

        printf("\nMENU\n");
        printf("1. DFS\n");
        printf("2. BFS\n");
        printf("3. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("DFS Traversal:\n");
            dfs(n, a, source, v);

            printf("\nCount: %d\n", count);
            break;

        case 2:
            printf("BFS Traversal:\n");
            bfs(n, a, source, v);

            printf("\nCount: %d\n", count);
            break;

        case 3:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice\n");
        }

    } while (choice != 3);

    return 0;
}