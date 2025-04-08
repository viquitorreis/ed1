#include "lista.h"

int main() {
    Cell *L;
    L = CreateInvertedList();
    ReadList(L);

    RemoveData(L);

    printf("Resultado da nova lista: ");
    ReadList(L);
}