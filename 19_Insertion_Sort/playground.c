#include <stdio.h>
void print(int arr[], int n, int iter){
    printf("\nInteration %d: ",iter);
    for (int i = 0; i < n; ++i)
        printf("\t%d\t", arr[i]);
    printf("\n");
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("\t%d\t", arr[i]);
    printf("\n");
}

void insertionSort(int arr[], int n)
{
    printf("\n-----Insertion Sort-----\n");
    int iter = 1;
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        print(arr, n, iter);
        iter++;
    }
    printf("\n Array After: ");
    printArray(arr, n);
}

void main()
{
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Array Before: ");
    printArray(arr, n);
    insertionSort(arr, n);
}