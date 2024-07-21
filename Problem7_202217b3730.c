#include <stdio.h>

#define MAX 100 // Define a maximum size for the array

void bubbleSort(int arr[], int n);
void displayArray(int arr[], int n);

int main() {
    int arr[MAX], n, i;

    // Read the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Check if the number of elements is within the allowed range
    if (n > MAX || n <= 0) {
        printf("Invalid number of elements. Must be between 1 and %d.\n", MAX);
        return 1;
    }

    // Read the elements of the array
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform Bubble Sort
    bubbleSort(arr, n);

    // Display the sorted array
    printf("Sorted array:\n");
    displayArray(arr, n);

    return 0;
}

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int swapped;

    // Loop through all array elements
    for (i = 0; i < n - 1; i++) {
        swapped = 0; // Flag to check if a swap occurred in this pass

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++) {
            // Swap if the element found is greater than the next element
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }

        // If no two elements were swapped, then the array is already sorted
        if (swapped == 0) {
            break;
        }
    }
}

// Function to display the elements of the array
void displayArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
