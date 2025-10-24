#include <stdio.h>

int partition(int a[], int start, int end) {
    int pivot = a[end];
    int i = start;
    
    for (int j = start; j < end; j++) {
        if (a[j] <= pivot) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
        }
    }
    int temp = a[i];
    a[i] = a[end];
    a[end] = temp;
    return i;
}

void quickSort(int a[], int start, int end) {
    if (start < end) {
        int pi = partition(a, start, end);
        quickSort(a, start, pi - 1);
        quickSort(a, pi + 1, end);
    }
}

int main() {
    int a[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(a) / sizeof(a[0]);
    
    printf("Before: ");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    
    quickSort(a, 0, n - 1);
    
    printf("\nAfter:  ");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    
    return 0;
}