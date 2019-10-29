#include "tMatrix.h"
#include <stdlib.h>

tMatrix* constructMatrix(){
    tMatrix* matrix = (tMatrix*) malloc(sizeof(tMatrix));
    matrix->n = 0;
    matrix->m = 0;
    matrix->capacity_row = 8;
    matrix->matrix = (tVector**) malloc(sizeof(tVector*) * matrix->capacity_row);
    int i;
    for(i = 0; i < matrix->capacity_row; i++)
        matrix->matrix[i] = constructVector();

    return matrix;
}
void insertMatrix(tMatrix* mat, void *data, int pos, void* (*tCopy)(void *data)){
    insertVector(mat->matrix[pos], data, tCopy);
}
void printMatrix(tMatrix* mat, void (*tPrint)(void *data)){
    int i;
    for(i = 0; i < mat->capacity_row; i++){
        printVector(mat->matrix[i], tPrint);
    }
}
void freeMatrix(tMatrix* mat){
    int i;
    for(i = 0; i < mat->capacity_row; i++){
        freeVector(mat->matrix[i]);
    }
    free(mat->matrix);
    free(mat);
}