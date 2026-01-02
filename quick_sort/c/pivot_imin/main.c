#include <stdio.h>

void readArr(int *arr, int size);
void printArr(int *arr, int size);
int partition(int *arr, int imin, int imax);
void recursion(int *arr, int imin, int imax);
void quickSort(int *arr, int size);

int main() {
    printf("== quickSort ==\n");
    
    int size = 10;
    int arr[size];

    printf("Digite 10 elementos a partir do vetor:\n");
    readArr(arr, size);
    
    printf("Array antes da ordenação:\n");
    printArr(arr, size);
    quickSort(arr, size);
    
    printf("Array depois da ordenação:\n");
    printArr(arr, size);
}

void readArr(int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        printf("digite um numero: ");
        scanf("%d", &arr[i]);
    }
}

void printArr(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void quickSort(int *arr, int size) {
    recursion(arr, 0, size - 1); // imin = 0 e imax = size - 1
}

void recursion(int *arr, int imin, int imax) {
    if (imin < imax) {
        int pivot = partition(arr, imin, imax);
        recursion(arr, imin, pivot-1); // ordenando a parte esquerda do array
        recursion(arr, pivot+1, imax); // ordenando a parte direita do array
    }
}
    
int partition(int *arr, int imin, int imax) {
    int pivot = arr[imin]; // pivô -> primeiro elemento
    int i = imin + 1;
    int j = imax;

    while (1) {
        while (i <= imax && arr[i] <= pivot) ++i;
        while (j >= imin && arr[j] > pivot) --j;

        if (i >= j) break;
        
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    arr[imin] = arr[j];
    arr[j] = pivot;

    return j;

}
