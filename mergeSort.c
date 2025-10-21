#include <stdlib.h>  // for malloc and free

void merge_sorted_arrays(int a[], int l, int m, int r)
{
  int left_length = m - l + 1;
  int right_length = r - m;

  int* temp_left = (int*)malloc(left_length * sizeof(int));
  int* temp_right = (int*)malloc(right_length * sizeof(int));
  
  int i, j, k;
  
  for (i = 0; i < left_length; i++)
    temp_left[i] = a[l + i];
  
  for (i = 0; i < right_length; i++)
    temp_right[i] = a[m + 1 + i];
  
  for (i = 0, j = 0, k = l; k <= r; k++)
  {
    if ((i < left_length) && (j >= right_length || temp_left[i] <= temp_right[j]))
    {
      a[k] = temp_left[i];
      i++;
    }
    else
    {
      a[k] = temp_right[j];
      j++;
    }
  }

  free(temp_left);
  free(temp_right);
}
