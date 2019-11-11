#ifndef T_MATRIX_H
#define T_MATRIX_H

#include "tVector.h"

typedef struct {
    int capacity;
    int n, m;
    tVector** matrix;
    void* (*defValue)();
    void (*tFree)(void*);
} tMatrix;

tMatrix* constructMatrix(int constColumns, void* (*defValue)(), void (*tFree)(void*));
int insertMatrix(tMatrix* mat, void *data, int pos_i, int pos_j, void* (*tCopy)(void *));
void printMatrix(tMatrix* mat, void (*tPrint)(void *));
void freeMatrix(tMatrix* mat);
int addVectorToMatrix(tMatrix *mat, tVector *vec, void* (*tCopy)(void*));
void addRowMatrix(tMatrix *mat, void* (*tCopy)(void*));

void sortMatrix(tMatrix* mat, int (*comp)(const void *, const void *));

#endif