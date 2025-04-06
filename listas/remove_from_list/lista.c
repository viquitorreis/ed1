#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int Data;
} DataType;

typedef struct Cell {
    struct Cell *Next;
    DataType *Data;
} Cell;

Cell* CreateInvertedList();
Cell* InsertEndOfList(Cell* list, DataType *data);
Cell* RemoveData(Cell *list);
Cell* RemoveDataFromList(Cell *list, DataType *data);

void ReadCellData(DataType *data);
void ReadList(Cell* list);
DataType* GetCellData();

int main() {
    Cell *L;
    L = CreateInvertedList();
    ReadList(L);

    RemoveData(L);

    printf("Resultado da nova lista: ");
    ReadList(L);
}

void ReadCellData(DataType *data) {
    printf("%d ", data->Data);
}

void ReadList(Cell* list) {
    Cell* cell = list; // aponta para a primeira célula da lista

    while (cell != NULL) {
        ReadCellData(cell->Data);
        cell = cell->Next;
    }

    printf("\n");
}

Cell* CreateInvertedList() {
    int escolha = 0;
    Cell *list = NULL;

    printf("Deseja criar uma lista?\n");
    while (1) {
        printf("0 - não\n");
        printf("1 - sim\n"); 
        scanf("%d", &escolha);

        if (escolha != 1) break;

        DataType *data = GetCellData();
        list = InsertEndOfList(list, data);
        printf("Deseja adicionar mais células na lista?\n");
    }

    return list;
}

Cell* RemoveData(Cell *list) {
    int escolha = 0;
    DataType *data;

    printf("Deseja remover uma célula da lista?\n");
    printf("0 - não\n");
    printf("1 - sim\n"); 
    scanf("%d", &escolha);

    if (escolha != 1) return list;

    data = GetCellData();
    return RemoveDataFromList(list, data);
}

Cell* InsertEndOfList(Cell* list, DataType *data) {
    Cell *p, *newList;

    newList = (Cell*) malloc(sizeof(Cell));
    if (newList == NULL) {
        printf("Falhou ao alocar memória\n");
        exit(1);
    }

    newList->Data = data;
    newList->Next = NULL;

    // caso a lista esteja vazia, a lista passada no parâmetro vai ser a que acabamos de criar
    if (list == NULL) {
        list = newList;
    } else {
        // se já existe, buscamos a última célula
        for (p = list; p->Next != NULL; p = p->Next) {}
        
        p->Next = newList;
    }

    return list;
}

DataType* GetCellData() {
    DataType *data = (DataType*) malloc(sizeof(DataType));
    if (data == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    
    printf("Dados da célula: ");
    scanf("%d", &data->Data);

    return data;
}

Cell* RemoveDataFromList(Cell *list, DataType *data) {
    Cell* current = list;
    Cell* prevNode = NULL;

    while (current != NULL) {
        if (current->Data->Data == data->Data) {
            printf("Removendo o elemento: %d\n", data->Data);
            
            if (prevNode == NULL) {
                // se não tinha nó anterior, vai remover a 'head' (ponta) da lista
                list = current->Next;
            } else {
                prevNode->Next = current->Next;
            }

            free(current->Data);
            free(current);
            break; 
        }

        prevNode = current; // prevNode será o endereço do nó anterior
        current = current->Next;
    }

    return list;
}

