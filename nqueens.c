#include <stdio.h>
#include <stdlib.h>

#define MAXN 10

int place(int x[MAXN], int row)
{
    for (int i = 0; i < row; i++)
    {
        if (x[i] == x[row])
            return 0;

        if (abs(x[row] - x[i]) == abs(row - i))
            return 0;
    }

    return 1;
}

void nqueen(int n)
{
    int x[MAXN];
    int row = 0;
    int count = 0;

    x[row] = -1;

    while (row >= 0)
    {
        x[row]++;

        while (x[row] < n && !place(x, row))
            x[row]++;

        if (x[row] < n)
        {
            if (row == n - 1)
            {
                count++;

                printf("\nSolution %d:\n", count);

                for (int i = 0; i < n; i++)
                    printf("%d ", x[i]);

                printf("\n");
            }
            else
            {
                row++;
                x[row] = -1;
            }
        }
        else
        {
            row--;
        }
    }

    printf("\nTotal Solutions = %d\n", count);
}

int main()
{
    int n;

    printf("Enter number of queens\n");
    scanf("%d", &n);

    if(n == 1 | n == 2||n==3){
        printf("Solutions dont exist\n");
        return 0;
    }

    nqueen(n);

    return 0;
}