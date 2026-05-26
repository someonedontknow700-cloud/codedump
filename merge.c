#include <stdio.h>
#include <time.h>

void merge(int a[], int low, int mid, int high)
{
    int i = low, k = low, j = mid + 1;
    int temp[high + 1];

    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= mid)
        temp[k++] = a[i++];
    while (j <= high)
        temp[k++] = a[j++];

    for(i=low;i<=high;i++) a[i]=temp[i];
}

void mergeSort(int a[], int low, int high)
{
    int mid = (low + high) / 2;
    if (low < high)
    {
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);

        merge(a, low, mid, high);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    clock_t start, end;

    start = clock();
    mergeSort(a, 0, n - 1);
    end = clock();

    float cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("time: %f", cpu_time);

    return 0;
}
