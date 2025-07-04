#include <stdio.h>

// Function to print array at each sorting phase
void printArrayPhase(int array[], int n, int phase) {
    printf("\nPhase %d: ", phase);
    for (int i = 0; i < n; i++) {
        printf("%d\t", array[i]);
    }
}

// Function to print final sorted array
void printArray(int array[], int n) {
    printf("\nArray after sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d\t", array[i]);
    }
}

// Bubble Sort in Ascending Order
void bubbleSort(int array[], int n) {
    int phase = 1;
    printf("\n-- Bubble Sort (Ascending Order) --");

    for (int i = 0; i < n; i++) {
        int j = 0;
        while (j < n - i - 1) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
            j++;
        }
        printArrayPhase(array, n, phase);
        phase++;
    }

    printArray(array, n);
}

// Main function
int main() {
    int array[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Original Array\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", array[i]);
    }

    bubbleSort(array, n);

    return 0;
}
