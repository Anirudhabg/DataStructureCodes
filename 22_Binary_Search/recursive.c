#include <stdio.h>

int binarySearch(int arr[], int low, int high, int x)
{
    if (high >= low) {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            return binarySearch(arr, mid + 1, high, x); // Search in the right half
        return binarySearch(arr, low, mid - 1, x); // Search in the left half
    }
    return -1;
}

void main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 5;

    int result = binarySearch(arr, 0, size - 1, target);
    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }
}