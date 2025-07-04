#include <stdio.h>

// Function to print the array
void printArray(int array[], int n) {
    printf("\nArray is:\t");
    for (int i = 0; i < n; i++) {
        printf("%d\t", array[i]);
    }
}

// Function to print the array after each iteration
void printIterations(int array[], int n, int iter) {
    printf("\nIteration %d:\t", iter);
    for (int i = 0; i < n; i++) {
        printf("%d\t", array[i]);
    }
}

// Function to perform Selection Sort in descending order
void selectionSort(int array[], int n) {
    int iter = 1;
    printf("\n-- Selection Sort (Descending Order) --");
    
    for (int i = 0; i < n - 1; i++) {
        int max = i;
        
        for (int j = i + 1; j < n; j++) {
            if (array[j] > array[max]) {
                max = j;
            }
        }

        // Swap the elements
        int temp = array[i];
        array[i] = array[max];
        array[max] = temp;

        printIterations(array, n, iter);
        iter++;
    }

    printArray(array, n);
}

// Main function
int main() {
    int array[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Array before sorting:");
    printArray(array, n);

    selectionSort(array, n);

    return 0;
}
