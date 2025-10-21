#include <stdio.h>
#include <stdlib.h>

// Function declarations
void quick_sort(int a[], int low, int high);
int partition(int a[], int low, int high);

// Main function with test array
int main() {
    int a[] = {9, 4, 8, 1, 7, 0, 3, 2, 5, 6};
    int n = sizeof(a) / sizeof(a[0]);

    quick_sort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}

// Quick sort function
void quick_sort(int a[], int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quick_sort(a, low, pi - 1);
        quick_sort(a, pi + 1, high);
    }
}

// Partition function (Lomuto partition scheme)
int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            // Swap a[i] and a[j]
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    // Swap pivot to correct position
    int temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    return i + 1;
}
