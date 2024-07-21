#include <stdio.h>

/* Function to perform linear search */
int linearSearch(int arr[], int size, int target) 
{
    for (int i = 0; i < size; i++) 
    {
        if (arr[i] == target) 
        {
            return i;  // Return the index of the target element
        }
    }
    return -1;  // Return -1 if the target element is not found
}

int main() 
{
    int arr[] = {12, 31, 25, 8, 32, 17};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 25;  // Element to search for

    int result = linearSearch(arr, size, target);

    if (result != -1) 
    {
        printf("Element %d found at index %d.\n", target, result);
    } 
    else 
    {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}
