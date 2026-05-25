#include <stdio.h>

#define INF 999999

void kruskal(int n, int cost[20][20])
{
    int parent[20];

    for(int i=0;i<n;i++)
        parent[i]=-1;

    int ne=1;
    int mincost=0;

    while(ne<n)
    {
        int a,b,u,v;
        int min=INF;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(cost[i][j]<min)
                {
                    min=cost[i][j];

                    a=u=i;
                    b=v=j;
                }
            }
        }

        while(parent[u]!=-1)
            u=parent[u];

        while(parent[v]!=-1)
            v=parent[v];

        if(u!=v)
        {
            printf(
                "%d edge (%d,%d)=%d\n",
                ne,
                a,
                b,
                min
            );

            mincost+=min;

            parent[v]=u;

            ne++;
        }

        cost[a][b]=cost[b][a]=INF;
    }

    printf("\nMinimum Cost=%d",mincost);
}

int main()
{
    int n;

    printf("Enter number of vertices:\n");
    scanf("%d",&n);

    int cost[20][20];

    printf("Enter adjacency matrix:\n");

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);

            if(i==j || cost[i][j]==0)
                cost[i][j]=INF;
        }
    }

    kruskal(n,cost);

    return 0;
}