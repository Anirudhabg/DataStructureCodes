#include <stdio.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertElement(int arr[], int size, int element, int position) {
    if (position < 0 || position > size) {
        printf("Invalid position!\n");
        return;
    }
    
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    size++;
    printf("Element %d inserted at position %d.\n", element, position);
}

void deleteElement(int arr[], int size, int position) {
    if (position < 0 || position >= size) {
        printf("Invalid position!\n");
        return;
    }
    
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    printf("Element at position %d deleted.\n", position);
}

void main(){
    int arr[100] = {1, 2, 3, 4, 5};
    int size = 5;

    printf("Original array: ");
    printArray(arr, size);

    insertElement(arr, size, 10, 2);
    printArray(arr, size);

    deleteElement(arr, size, 3);
    printArray(arr, size);
}