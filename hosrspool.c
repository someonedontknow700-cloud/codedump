#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int horspool(char T[], char P[], int n, int m)
{
    int ST[256];
    for (int i = 0; i < 256; i++)
    {
        ST[i] = m;
    }
    for (int i = 0; i < m - 1; i++)
    {
        ST[P[i]] = m - i - 1;
    }

    int i = m - 1;
    while (i < n)
    {
        int j = 0;
        while (j < m && P[m - j - 1] == T[i - j])
        {
            j++;
        }

        if (j == m)
            return (i - m + 1);

        i += ST[T[i]];
    }

    return -1;
}

int main()
{
    printf("Enter text:\n");
    char T[100];
    fgets(T, sizeof(T), stdin);

    printf("enter pattern:\n");
    char P[100];
    fgets(P, sizeof(P), stdin);

    T[strcspn(T, "\n")] = '\0';
    P[strcspn(P, "\n")] = '\0';

    int n = strlen(T), m = strlen(P);

    int ans = horspool(T, P, n, m);

    if (ans == -1)
    {
        printf("String not found\n");
    }
    else
    {
        printf("String found at position %d", ans);
    }

    return 0;
}
