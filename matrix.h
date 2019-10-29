#include "vector.h"

typedef struct tMatrix{
    int n, m;
    Vector** matrix;
} Matrix;

Matrix* constructMatrix();
void insertMatrix(Matrix* mat, void *data, int pos, void* (*tCopy)(void *data));
void printMatrix(Matrix* mat, void (*tPrint)(void *data));