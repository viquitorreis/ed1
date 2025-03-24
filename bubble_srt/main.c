#include <stdio.h>

void bubbleSort(int *arr, int size);
void readArr(int *arr, int size);

int main() {
    int arr[] = {10,20,30,5,4,3,2,1};
    bubbleSort(arr, 8);
    readArr(arr, 8);
}

void bubbleSort(int *arr, int size) {
    int i, j, temp;
    for (j = size - 1; j >= 0; --j) {
        // subir o maior número
        for (i = 1; i <= j; ++i) {
            if (arr[i] < arr[i - 1]) {
                // swap T[i-1] et T[i]
                temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
            }
        }
    }
}

void readArr(int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}