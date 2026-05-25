#include <stdio.h>
#include <limits.h>

int MCM(int p[], int i, int j)
{
    if(i == j)
        return 0;

    int min = INT_MAX;

    for(int k = i; k < j; k++)
    {
        int count =
            MCM(p, i, k)
            + MCM(p, k + 1, j)
            + p[i - 1] * p[k] * p[j];

        if(count < min)
            min = count;
    }

    return min;
}

int main()
{
    int arr[20];
    int n;

    printf("Enter the number of matrices:\n");
    scanf("%d", &n);

    printf("Enter the dimensions (p0 p1 ... p%d):\n", n);

    for(int i = 0; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int result = MCM(arr, 1, n);

    printf("Minimum number of multiplications is: %d\n", result);

    return 0;
}