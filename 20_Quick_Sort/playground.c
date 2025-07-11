#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int arr[], int left, int right){
    int pivot = arr[left];
    int i = left + 1;
    int j = right;

    while(i <= j){
        while(i <= right && arr[i] <= pivot) i++;
        while(j >= left && arr[j] > pivot) j--;
        if(i < j){
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[left], &arr[j]);
    return j;
}

void QuickSort(int arr[], int left, int right){
    if(left < right){
        int part = Partition(arr, left, right);
        QuickSort(arr, left, part - 1);
        QuickSort(arr, part + 1, right);
    }
}

int main() {
    int arr[] = {77, 33, 44, 11, 88, 22, 66, 55};
    int left = 0;
    int right = sizeof(arr)/sizeof(arr[0]) - 1;

    QuickSort(arr, left, right);

    printf("Array after QuickSort:\n");
    for(int i = 0; i <= right; i++){
        printf("%d\t", arr[i]);
    }

    return 0;
}
