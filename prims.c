#include <stdio.h>

#define INF 999

int prim(int n, int a[10][10], int source)
{
    int s[10];
    int d[10];

    int sum = 0;

    for(int i=0;i<n;i++)
    {
        s[i]=0;
        d[i]=a[source][i];
    }

    s[source]=1;

    for(int i=0;i<n-1;i++)
    {
        int min=INF;
        int u=-1;

        for(int j=0;j<n;j++)
        {
            if(s[j]==0 && d[j]<min)
            {
                min=d[j];
                u=j;
            }
        }

        if(u==-1)
            break;

        s[u]=1;

        sum+=d[u];

        for(int k=0;k<n;k++)
        {
            if(
                s[k]==0 &&
                a[u][k]<d[k]
            )
            {
                d[k]=a[u][k];
            }
        }
    }

    return sum;
}

int main()
{
    int n;

    printf("Enter number of vertices:\n");
    scanf("%d",&n);

    int a[10][10];

    printf("Enter adjacency matrix:\n");

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);

            if(i!=j && a[i][j]==0)
                a[i][j]=INF;
        }
    }

    int source;

    printf("Enter source vertex:\n");
    scanf("%d",&source);

    int ans=prim(n,a,source);

    printf(
        "\nMinimum Cost = %d",
        ans
    );

    return 0;
}