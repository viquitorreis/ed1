#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int Data;
} TipoDado; 

typedef struct TipoCelula {
    struct TipoCelula *Next;
    TipoDado *Data;
} TipoCelula;

TipoCelula *CreateInvertedList();
TipoCelula *ConcatenateTwoLists(TipoCelula *L1, TipoCelula *L2);
TipoDado *GetCellData();
TipoCelula *InsertIntoCell(TipoCelula *oldList, TipoDado *data);
void ReadCellData(TipoDado *data);
void ReadList(TipoCelula *list);

int main() {
    TipoCelula *listOne, *listTwo, *listConcat;

    printf("Criação da primeira lista\n");
    listOne = CreateInvertedList();

    printf("Primeira lista: ");
    ReadList(listOne);

    printf("Criação da segunda lista\n");
    listTwo = CreateInvertedList();

    printf("Segunda lista: ");
    ReadList(listTwo);

    printf("Concatenando as listas...\n");
    listConcat = ConcatenateTwoLists(listOne, listTwo);

    printf("Lista concatenada: ");
    ReadList(listConcat);

    return 0;
}

TipoCelula* CreateInvertedList() {
    int escolha = 0;
    TipoCelula *list = NULL;

    printf("Deseja criar uma lista?\n");
    while (1) {
        printf("0 - não\n");
        printf("1 - sim\n"); 
        scanf("%d", &escolha);

        if (escolha != 1) break;

        TipoDado *data = GetCellData();
        list = InsertIntoCell(list, data); 
        printf("Deseja adicionar mais células na lista?\n");
    }

    return list;
}

TipoCelula* InsertIntoCell(TipoCelula *oldList, TipoDado *data) {
    TipoCelula *newList;

    newList = (TipoCelula*) malloc(sizeof(TipoCelula));
    if (newList == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    newList->Data = data;
    newList->Next = oldList;

    return newList;
}

TipoCelula *ConcatenateTwoLists(TipoCelula *L1, TipoCelula *L2) {
    if (L1 == NULL) return L2;

    TipoCelula *current = L1;
    
    while (current->Next != NULL) {
        current = current->Next;
    }
    
    current->Next = L2;
    return L1;
}

TipoDado *GetCellData() {
    TipoDado *data = (TipoDado*) malloc(sizeof(TipoDado));
    if (data == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    
    printf("Dados da célula: ");
    scanf("%d", &data->Data);

    return data;
}

void ReadCellData(TipoDado *data) {
    printf("%d ", data->Data);
}

void ReadList(TipoCelula *list) {
    TipoCelula *cell = list; // aponta para a primeira célula da lista

    while (cell != NULL) {
        ReadCellData(cell->Data);
        cell = cell->Next;
    }
    
    printf("\n");
}