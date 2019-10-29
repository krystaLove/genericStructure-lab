#include "matrix.h"
#include <stdlib.h>

Matrix* constructMatrix(){
    Matrix* matrix = (Matrix*) malloc(sizeof(Matrix));
    matrix->n = 8;
    matrix->m = 8;
    matrix->matrix = (Vector**) malloc(sizeof(Vector*) * matrix->n);
    int i;
    for(i = 0; i < matrix->n; i++)
        matrix->matrix[i] = constructVector();
}
void insertMatrix(Matrix* mat, void *data, int pos, void* (*tCopy)(void *data)){
    insertVector(mat->matrix[pos], data, tCopy);
}
void printMatrix(Matrix* mat, void (*tPrint)(void *data)){
    int i;
    for(i = 0; i < mat->n; i++){
        printVector(mat->matrix[i], tPrint);
    }
}