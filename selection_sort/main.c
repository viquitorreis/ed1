#include <stdio.h>

int lerVetor(int *arr, int n);
int imprimirVetor(int *arr, int n);
int selectionSort(int *arr, int n);

int main() {
    int arr[11];
    int n = 11;
    printf("Digite 10 números para o vetor:\n");
    lerVetor(arr, n);
    imprimirVetor(arr, n);
    
    selectionSort(arr, n);

    printf("Array depois da ordenação: \n");
    imprimirVetor(arr, n);

    return 0;
}

int lerVetor(int *arr, int n) {
    int i;
    for (i = 0;i < n - 1; ++i) {
        printf("Digite um número: ");
        scanf("%d", &arr[i]);
    }
}

int imprimirVetor(int *arr, int n) {
    int i;
    for (i = 0; i < n - 1; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int selectionSort(int *arr, int n) {
    int k, i, imax, temp;
    for (k = n-1; k >= 1; --k) {
        // busca o índice do valor max
        imax = 0;
        for (i = 1; i <= k; ++i) {
            if (arr[imax] < arr[i]) {
                imax = i;
            }
        }
        // swap
        temp = arr[k];
        arr[k] = arr[imax];
        arr[imax] = temp;
    }
}