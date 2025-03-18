#include <stdio.h>

// 1. Escolher o pivo
// 2. Particionamento (divide) -> reorganizar. Elementos menores que o pivô ficam a esquerda, maiores a direita.
// 3. Recursão -> quicksort chamado muitas vezes até ordenas as duas partições
// 4. Conquista (conquer) -> continua até que o 'subvetor' tenha zero ou só um elemento, ou seja, está ordenado

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

// Partition: a função mais importante do quicksort.
// - Elementos menores que o pivô ficam a esquerda
// - Elementos maiores que o pivô ficam a direita
// - O pivô é colocado na posição correta
// Naive Partition
//      1. Colocamos todos elementos menores e todos maiores
//      2. copiamos a array temporária na original -> O(n) espaço
// Lomuto Partition (mais simples)
//      1. Nesse caso monitoramos o índice dos elementos menores, e ficamos fazendo swap deles.
// Hoare's Partition
//      É o mais rápido de todos. Aqui vamos percorrer o array nos dois lados e então fazer o swap do maior elemento
//      da esquerda com o da direita, enquanto o array não é particionado
int partition(int *arr, int imin, int imax) {
    int pivot = arr[imax]; // pivô -> ultimo elemento
    int i = imin ; // menor elemento
    int j = imax - 1; // maior elemento

    // precisamos percorrer arr[low...high] e mover todos os menores
    // elementos para o lado esquerdo. Elementos da parte menor
    // até i são menores após cada iteração
    while (i <= j) {
        // caso o menor indice for menor ou igual ao maior indice
        // e o elemento for menor que o elemento do indice i (menor el),
        // então somamos o indice MENOR para swap posterior
        // Caso contrário é ele o menor, então não tem pq subtrair
        // while (i <= j && arr[i] <= pivot) i++;
        while (i < imax && arr[i] <= pivot) i++; // tá ordenado então soma em i até achar o arr[i] maior que arr[j]

        // se o elemento de maior indice for maior que o elemento do indice i
        // Caso contrário é ele o maior, então não tem pq somar
        // while (i <= j && arr[j] >= pivot) j--;
        while (j >= imin && arr[j] >= pivot) j--;

        // swap caso i <= j
        if (i <= j) {
            // temp recebe o maior elemento temporário
            int temp = arr[i];
            // maior elemento recebe arr[maiorElem]
            // é usado para swap com o pivô depois
            arr[i] = arr[j];
            arr[j] = temp;
        }

        // coloca o pivo na posição correta
        arr[imax] = arr[i];
        // o pivô é colocado na posição i, assim todos os menores ficam a esquerda
        // e os maiores a direita
        arr[i] = pivot;

        return i;
    }
}

void recursion(int *arr, int imin, int imax) {
    int i;
    if (imin < imax) {
        i = partition(arr, imin, imax);
        recursion(arr, imin, i-1); // ordenamento da parte esquerda
        recursion(arr, i+1, imax); // prdenamento da parte direita
    }
}

void quickSort(int *arr, int size) {
    recursion(arr, 0, size - 1); // imin = 0 e imax = n - 1
}