#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int elements;
} ElementsType;

typedef struct {
    int size;
    int maxSize;
    ElementsType *elements;
} Stack;

Stack initStack(int max);
int isStackEmpty(Stack s);
int isFull(Stack s);
int lastStackElement(Stack s, ElementsType *el); // Topo da lista -> ultimo elemento inserido
int doStack(Stack *stPointer, ElementsType el);
int undoStack(Stack *stPointer, ElementsType *el);
void emptyStack(Stack *stPointer);
void destroyStack(Stack *stPointer);
void printStack(Stack *stPointer);

int main() {
    Stack myStack = initStack(10);
    ElementsType value;
    int opcao, resultado;
    
    for(;;) {
        printf("====  MENU ====\n");
        printf("1 - Empilhar\n");
        printf("2 - Desempilhar\n");
        printf("3 - Ver topo da pilha\n");
        printf("4 - Imprimir pilha\n");
        printf("5 - Esvaziar pilha\n");
        printf("0 - Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                printf("Digite o valor a empilhar: ");
                ElementsType val;
                scanf("%d", &val.elements);
                resultado = doStack(&myStack, val);
                if (resultado == 0)
                    printf("Valor empilhado com sucesso!\n");
                else
                    printf("Erro: pilha cheia!\n");
                break;
                
            case 2:
                resultado = undoStack(&myStack, &value);
                if (resultado == 0) {
                    printf("Valor desempilhado: %d\n", value.elements);
                } else {
                    printf("A pilha está vazia. Nada a desempilhar.\n");
                }
                break;
                
            case 3:
                resultado = lastStackElement(myStack, &value); 
                if (resultado == 0) {
                    printf("Topo da pilha: %d\n", value.elements);
                } else {
                    printf("Pilha está vazia.\n");
                }
                break;
                
            case 4:
                printf("Conteúdo da pilha:\n");
                printStack(&myStack);
                break;
                
            case 5:
                emptyStack(&myStack);
                printf("Pilha esvaziada.\n");
                break;
                
            case 0:
                printf("Terminando programa\n");
                destroyStack(&myStack);
                return 0;
                
            default:
                printf("Opcao invalida!\n");
        }
        printf("\n");
    }
    return 0;
}

Stack initStack(int max) {
    Stack emptyStack;
    emptyStack.size = 0; // inicializando pilha vazia
    emptyStack.maxSize = max;
    emptyStack.elements = (ElementsType*) malloc(max*sizeof(ElementsType));
    return emptyStack;
}

int isStackEmpty(Stack s) {
    return (s.size == 0) ? 1 : 0;
}

// retorna 1 caso seja maior ou igual a capacidade da pilha, caso contrario 0
int isFull(Stack s) {
    return (s.size >= s.maxSize) ? 1 : 0;
}

int lastStackElement(Stack s, ElementsType *el) {
    if (isStackEmpty(s)) return 1; /// retorna código de erro
    *el = s.elements[s.size-1]; // salvando o topo da pilha
    return 0; 
}

int doStack(Stack *stPointer, ElementsType el) {
    if (isFull(*stPointer)) return 1; // pilha cheia não acrescenta elemento
    stPointer->elements[stPointer->size] = el;
    stPointer->size++;
    return 0;
}

int undoStack(Stack *stPointer, ElementsType *el) {
    if (isStackEmpty(*stPointer)) return 1;
    *el = stPointer->elements[stPointer->size-1];
    stPointer->size--;
    return 0;
}

void emptyStack(Stack *stPointer) {
    stPointer->size = 0; // reiniciando a quantidade de elementos da pilhar
}

void destroyStack(Stack *stPointer) {
    if (stPointer->maxSize != 0) free(stPointer->elements); 
    stPointer->size = 0;
    stPointer->maxSize = 0;
}

void printStack(Stack *stPointer) {
    if (isStackEmpty(*stPointer)) {
        printf("Pilha vazia!\n");
        return;
    }
    
    printf("Base [");
    for (int i = 0; i < stPointer->size; i++) {
        printf(" %d", stPointer->elements[i].elements);
        if (i < stPointer->size - 1)
            printf(",");
    }
    printf(" ] Topo\n");
}