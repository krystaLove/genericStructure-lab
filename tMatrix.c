#include "tMatrix.h"
#include <stdlib.h>
#include <stdio.h>
tMatrix* constructMatrix(int constColumns){
    tMatrix* matrix = (tMatrix*) malloc(sizeof(tMatrix));
    matrix->n = 0;
    matrix->m = constColumns;
    matrix->capacity_row = 8;
    matrix->matrix = (tVector**) malloc(sizeof(tVector*) * matrix->capacity_row);
    int i;
    for(i = 0; i < matrix->capacity_row; i++) {
        matrix->matrix[i] = constructVector(constColumns);
    }

    return matrix;
}
void addRowMatrix(tMatrix *mat){
    if(mat->n + 1 >= mat->capacity_row){
        mat->capacity_row *= 2;
        mat->matrix = realloc(mat->matrix, sizeof(tVector*) * mat->capacity_row);
    }
    mat->matrix[mat->n] = constructVector(mat->m);
    mat->n++;
}
int addVectorToMatrix(tMatrix *mat, tVector *vec, void* (*tCopy)(void*)){
    if(vec->size > mat->m) return -1;
    addRowMatrix(mat);
    free(mat->matrix[mat->n - 1]);
    mat->matrix[mat->n - 1] = copyVector(vec, tCopy);
    return 1;
}
int insertMatrix(tMatrix* mat, void *data, int pos_i, int pos_j, void* (*tCopy)(void *)){
    if(pos_i >= mat->n || pos_j >= mat->m) return -1;
    changeValueByPosVector(mat->matrix[pos_i], pos_j, data, tCopy);
    return 0;
}
void printMatrix(tMatrix* mat, void (*tPrint)(void *)){
    int i;
    for(i = 0; i < mat->n; i++){
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
