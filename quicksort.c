#include <stdio.h>
#include <time.h>

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;

    while (1)
    {
        while (i <= high && a[i] <= pivot)
            i++;

        while (a[j] > pivot)
            j--;

        if (i < j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        else
        {
            int temp = a[low];
            a[low] = a[j];
            a[j] = temp;

            return j;
        }
    }
}

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int j = partition(a, low, high);

        quickSort(a, low, j - 1);
        quickSort(a, j + 1, high);
    }
}

int main()
{
    int n;

    printf("Enter size: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    clock_t start = clock();

    quickSort(a, 0, n - 1);

    clock_t end = clock();

    double cpu_time =
        ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array:\n");

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\nTime: %lf seconds\n", cpu_time);

    return 0;
}