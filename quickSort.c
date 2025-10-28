#include <stdio.h>

int a[100];
void quicksort(int low, int high);
int partition(int low, int high);

void main()
{
    int i, n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements one by one:\n");
    for (i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    quicksort(0, n - 1);

    printf("\n--- Sorted Array ---\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void quicksort(int low, int high)
{
    if (low < high)
    {
        int p;
        p = partition(low, high);
        quicksort(low, p - 1);
        quicksort(p + 1, high);
    }
}

int partition(int low, int high)
{
    int temp;
    int pivot = a[high];
    int i = low - 1;
    int j;

    for (j = low; j < high; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    return i + 1;
}