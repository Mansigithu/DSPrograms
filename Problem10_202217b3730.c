#include <stdio.h>
#include <stdlib.h>

/* Function to merge two halves of the array */
void merge(int arr[], int beg, int mid, int end) 
{
    int n1 = mid - beg + 1;
    int n2 = end - mid;

    /* Create temporary arrays */
    int *left = (int *)malloc(n1 * sizeof(int));
    int *right = (int *)malloc(n2 * sizeof(int));

    /* Copy data to temporary arrays */
    for (int i = 0; i < n1; i++)
        left[i] = arr[beg + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];

    /* Merge the temporary arrays back into arr */
    int i = 0, j = 0, k = beg;
    while (i < n1 && j < n2) 
    {
        if (left[i] <= right[j]) 
        {
            arr[k] = left[i];
            i++;
        } 
        else 
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of left[], if any */
    while (i < n1) 
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of right[], if any */
    while (j < n2) 
    {
        arr[k] = right[j];
        j++;
        k++;
    }

    /* Free temporary arrays */
    free(left);
    free(right);
}

/* Function to implement merge sort */
void mergeSort(int arr[], int beg, int end) 
{
    if (beg < end) 
    {
        int mid = beg + (end - beg) / 2;

        mergeSort(arr, beg, mid);
        mergeSort(arr, mid + 1, end);

        merge(arr, beg, mid, end);
    }
}

/* Function to print the array */
void printArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() 
{
    int arr[] = {12, 31, 25, 8, 32, 17};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting: \n");
    printArray(arr, size);

    mergeSort(arr, 0, size - 1);

    printf("After sorting: \n");
    printArray(arr, size);

    return 0;
}
