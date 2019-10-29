#include "tMatrix.h"
#include <stdlib.h>

tMatrix* constructMatrix(int constColumns){
    tMatrix* matrix = (tMatrix*) malloc(sizeof(tMatrix));
    matrix->n = 0;
    matrix->m = constColumns;
    matrix->capacity_row = 8;
    matrix->matrix = (tVector**) malloc(sizeof(tVector*) * matrix->capacity_row);

    int i;
    for(i = 0; i < matrix->capacity_row; i++) {
        matrix->matrix[i] = constructVector(constColumns);
        /*for(j = 0; j < matrix->m; j++){
            int add = 0;
            //insertVector(matrix->matrix[i], &add, )
        }*/
    }

    return matrix;
}
void insertMatrix(tMatrix* mat, void *data, int pos, void* (*tCopy)(void *)){
    insertVector(mat->matrix[pos], data, tCopy);
}
void printMatrix(tMatrix* mat, void (*tPrint)(void *)){
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