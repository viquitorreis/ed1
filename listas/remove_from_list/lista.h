#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>

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
Cell* RemoveDataFromList2(Cell *list, DataType *data);


void ReadCellData(DataType *data);
void ReadList(Cell* list);
DataType* GetCellData();

#endif