#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    return (a > b ? a : b);
}

int lcs(char x[], char y[], int m, int n)
{
    int l[101][101];
    char lc[101];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                l[i][j] = 0;
            else if (x[i - 1] == y[j - 1])
                l[i][j] = l[i - 1][j - 1] + 1;
            else
                l[i][j] = max(l[i - 1][j], l[i][j - 1]);
        }
    }

    int len = l[m][n];
    printf("Max length is %d\n", len);

    lc[len] = '\0';

    int i = m, j = n;

    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            lc[len - 1] = x[i - 1];
            i--;
            j--;
            len--;
        }
        else
        {
            if (l[i - 1][j] > l[i][j - 1])
                i--;
            else
                j--;
        }
    }

    printf("The lcs is %s", lc);
}

int main()
{
    printf("Enter x\n");
    char x[100];
    fgets(x, sizeof(x), stdin);

    printf("Enter y:\n");
    char y[100];
    fgets(y, sizeof(y), stdin);

    x[strcspn(x, "\n")] = '\0';
    y[strcspn(y, "\n")] = '\0';

    int m = strlen(x), n = strlen(y);
    lcs(x, y, m, n);
}
