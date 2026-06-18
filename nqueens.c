#include <stdio.h>
#include <stdlib.h>

int place(int x[], int k);
void nqueen(int n);

int main()
{
    int n;

    printf("Enter the number of queens: ");
    scanf("%d", &n);

    if (n == 1 || n == 2 || n == 3)
    {
        printf("Solution is not possible\n");
    }
    else
    {
        nqueen(n);
    }

    return 0;
}

void nqueen(int n)
{
    int x[10], k = 1, i, count = 0;

    x[k] = 0;

    while (k != 0)
    {
        x[k] = x[k] + 1;

        while (x[k] <= n && place(x, k) == 0)
        {
            x[k] = x[k] + 1;
        }

        if (x[k] <= n)
        {
            if (k == n)
            {
                count++;
                printf("\nSolution %d:\n", count);

                for (i = 1; i <= n; i++)
                {
                    printf("%d ", x[i]);
                }
                printf("\n");
            }
            else
            {
                k++;
                x[k] = 0;
            }
        }
        else
        {
            k--;
        }
    }
}

int place(int x[], int k)
{
    int i;

    for (i = 1; i <= k - 1; i++)
    {
        if (x[i] == x[k])
            return 0;

        if (abs(x[i] - x[k]) == abs(i - k))
            return 0;
    }

    return 1;
}