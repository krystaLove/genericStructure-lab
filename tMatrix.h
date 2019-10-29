#include "tVector.h"

typedef struct {
    int capacity_row;
    int n, m;
    tVector** matrix;
} tMatrix;

tMatrix* constructMatrix();
void insertMatrix(tMatrix* mat, void *data, int pos, void* (*tCopy)(void *));
void printMatrix(tMatrix* mat, void (*tPrint)(void *));
void freeMatrix(tMatrix* mat);