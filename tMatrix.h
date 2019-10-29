#include "vector.h"

typedef struct {
    int capacity_row;
    int n, m;
    tVector** matrix;
} tMatrix;

tMatrix* constructMatrix();
void insertMatrix(tMatrix* mat, void *data, int pos, void* (*tCopy)(void *data));
void printMatrix(tMatrix* mat, void (*tPrint)(void *data));
void freeMatrix(tMatrix* mat);