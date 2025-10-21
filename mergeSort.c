#include <stdio.h>
#include <stdlib.h>
//First define merge and marge_sort
void merge_sort(int a[], int l, int r);
void merge(int a[], int l, int m, int r);
//main function which calls the function and contains the test array
int main() {
    int a[] = {9, 4, 8, 1, 7, 0, 3, 2, 5, 6};
    int n = sizeof(a) / sizeof(a[0]);

    merge_sort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}
//Defining the merge_sort fn 
void merge_sort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        merge_sort(a, l, m);
        merge_sort(a, m + 1, r);
        merge(a, l, m, r);
    }
}
//Defining
void merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = a[l + i];
    for (int i = 0; i < n2; i++) R[i] = a[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        a[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];

    free(L);
    free(R);
}
