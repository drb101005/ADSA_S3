#include <stdio.h>

void merge(int a[], int start, int mid, int end) {
    int i, j, k, temp[end - start + 1];
    i = start; j = mid + 1; k = 0;
    
    while (i <= mid && j <= end)
        temp[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];
    
    while (i <= mid) temp[k++] = a[i++];
    while (j <= end) temp[k++] = a[j++];
    
    for (i = start, k = 0; i <= end; i++, k++)
        a[i] = temp[k];
}

void mergeSort(int a[], int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        mergeSort(a, start, mid);
        mergeSort(a, mid + 1, end);
        merge(a, start, mid, end);
    }
}

int main() {
    int a[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(a) / sizeof(a[0]);
    
    printf("Before: ");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    
    mergeSort(a, 0, n - 1);
    
    printf("\nAfter:  ");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    
    return 0;
}