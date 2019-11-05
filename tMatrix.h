#include "tVector.h"

typedef struct {
    int capacity_row;
    int n, m;
    tVector** matrix;
} tMatrix;

tMatrix* constructMatrix(int);
int insertMatrix(tMatrix* mat, void *data, int pos_i, int pos_j, void* (*tCopy)(void *));
void printMatrix(tMatrix* mat, void (*tPrint)(void *));
void freeMatrix(tMatrix* mat);
int addVectorToMatrix(tMatrix *mat, tVector *vec, void* (*tCopy)(void*));
void addRowMatrix(tMatrix *mat);