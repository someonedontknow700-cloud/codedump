#include <stdio.h>

int s[10], x[10];
int d, flag = 0;

void sumofsub(int m, int k, int r)
{
    int i;

    x[k] = 1;   

    if (m + s[k] == d)
    {
        printf("{ ");
        for (i = 1; i <= k; i++)
        {
            if (x[i] == 1)
                printf("%d ", s[i]);
        }
        printf("}\n");
        flag = 1;
    }
    else
    {
        if (m + s[k] + s[k + 1] <= d)
            sumofsub(m + s[k], k + 1, r - s[k]);

        if ((m + r - s[k] >= d) && (m + s[k + 1] <= d))
        {
            x[k] = 0;
            sumofsub(m, k + 1, r - s[k]);
        }
    }
}

int main()
{
    int n, i, sum = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements in increasing order:\n");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &s[i]);
        sum += s[i];
    }

    printf("Enter required sum: ");
    scanf("%d", &d);

    if (sum < d || s[1] > d)
    {
        printf("No subset possible\n");
        return 0;
    }

    sumofsub(0, 1, sum);

    if (flag == 0)
        printf("No subset possible\n");

    return 0;
}