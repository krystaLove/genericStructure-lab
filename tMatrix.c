#include <stdlib.h>
#include <stdio.h>

#include "tMatrix.h"

tMatrix* constructMatrix(int constColumns, void* (*defValue)()){
    tMatrix* matrix = (tMatrix*) malloc(sizeof(tMatrix));
    matrix->n = 0;
    matrix->m = constColumns;
    matrix->capacity = 8;
    matrix->matrix = (tVector**) calloc(sizeof(tVector*), matrix->capacity);
    matrix->defValue = defValue;

    return matrix;
}
void addRowMatrix(tMatrix *mat, void* (*tCopy)(void*)){
    if(mat->n + 1 >= mat->capacity){
        mat->capacity *= 2;
        mat->matrix = realloc(mat->matrix, sizeof(tVector*) * mat->capacity);
    }
    mat->matrix[mat->n] = constructVector(mat->m);
    fillVector(mat->matrix[mat->n], mat->m, mat->defValue, tCopy);
    mat->n++;
}
int addVectorToMatrix(tMatrix *mat, tVector *vec, void* (*tCopy)(void*)){
    if(vec->size > mat->m) return -1;

    addRowMatrix(mat, tCopy);
    freeVector(mat->matrix[mat->n - 1]);
    mat->matrix[mat->n - 1] = copyVector(vec, tCopy);

    return 1;
}
int insertMatrix(tMatrix* mat, void *data, int pos_i, int pos_j, void* (*tCopy)(void *), void (*tCopyTo)(void*, void*)){
    if(pos_i > mat->n || pos_j >= mat->m) return -1;
    if(pos_i == mat->n) addRowMatrix(mat, tCopy);
    changeValueByPosVector(mat->matrix[pos_i], pos_j, data, tCopy, tCopyTo);
    return 0;
}
void printMatrix(tMatrix* mat, void (*tPrint)(void *)){
    int i, j;
    for(i = 0; i < mat->n; i++){
        printVector(mat->matrix[i], tPrint);
        for(j = mat->matrix[i]->size; j < mat->m; j++)
            printf("NULL ");
        printf("\n");
    }
}
void freeMatrix(tMatrix* mat){
    int i;
    for(i = 0; i < mat->n; i++){
        freeVector(mat->matrix[i]);
       // printf("CLEANING VECTOR\n");
    }
    free(mat->matrix);
    free(mat);
}
void sortMatrix(tMatrix* mat, void (*swap) (void*, void*), int (*comp)(const void *, const void *)){
    int i;
    for(i = 0; i < mat->n; i++){
        sortVector(mat->matrix[i], swap, comp);
    }
}
