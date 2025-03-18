#include <stdio.h>

int lerVetor(int *T, int n);
int imprimirVetor(int *T, int n);
int selectionSort(int *T, int n);

int main() {
    int T[11];
    int n = 11;
    printf("Digite 10 números para o vetor:\n");
    lerVetor(T, n);
    imprimirVetor(T, n);
    
    selectionSort(T, n);

    printf("Array depois da ordenação: \n");
    imprimirVetor(T, n);

    return 0;
}

int lerVetor(int *T, int n) {
    int i;
    for (i = 0;i < n - 1; ++i) {
        printf("Digite um número: ");
        scanf("%d", &T[i]);
    }
}

int imprimirVetor(int *T, int n) {
    int i;
    for (i = 0; i < n - 1; ++i) {
        printf("%d ", T[i]);
    }
    printf("\n");
}

int selectionSort(int *T, int n) {
    int k, i, imax, temp;
    for (k = n-1; k >= 1; --k) {
        // busca o índice do valor max
        imax = 0;
        for (i = 1; i <= k; ++i) {
            if (T[imax] < T[i]) {
                imax = i;
            }
        }
        // swap
        temp = T[k];
        T[k] = T[imax];
        T[imax] = temp;
    }
}