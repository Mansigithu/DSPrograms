#include <stdio.h>

// Function to find the index of the smallest element
int smallest(int arr[], int i, int n) {
    int pos = i;
    for (int j = i + 1; j < n; j++) {
        if (arr[j] < arr[pos]) {
            pos = j;
        }
    }
    return pos;
}

// Function to perform Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Find the smallest element in the unsorted part of the array
        int pos = smallest(arr, i, n);
        
        // Swap the found smallest element with the first element of the unsorted part
        if (pos != i) {
            int temp = arr[i];
            arr[i] = arr[pos];
            arr[pos] = temp;
        }
    }
}

// Function to display the array
void displayArray(int arr[], int n) {
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    selectionSort(arr, n);
    
    displayArray(arr, n);
    
    return 0;
}
