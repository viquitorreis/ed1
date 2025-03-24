#include <stdio.h>

void printArr(int *arr, int size);
void insertionSort(int *arr, int size);

int main() {
    int arr[] = {20, 10, 30, 4, 2};
    insertionSort(arr, 5);
    printArr(arr, 5);

    return 0;
}

void insertionSort(int *arr, int size) {
    int k = 0, i = 0, v = 0;
    for (int k = 1; k >= i && k <= size; ++k) {
        i = k - 1;
        v = arr[k];

        for (i = i; i >= 0 && v < arr[i]; i = i - 1) {
            arr[i + 1] = arr[i];
        }

        // inserção
        arr[i + 1] = v;
    }
}

void printArr(int *arr, int size) {
    printf("array: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}