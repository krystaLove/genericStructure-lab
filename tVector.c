#include "tVector.h"
#include <stdlib.h>
#include <stdio.h>
tVector* constructVector(int startCapacity){
    tVector* vector = (tVector*) malloc(sizeof(tVector));
    vector->capacity = startCapacity;
    vector->size = 0;
    vector->array = calloc(sizeof(void*), vector->capacity);
}

void insertVector(tVector *v, void* data, void* (*tCopy)(void*)){
    if(v->size + 1 > v->capacity){
        v->capacity *= 2;
        v->array = realloc(v->array, v->capacity * sizeof(void*));
    }
    v->array[v->size++] = tCopy(data);
}
void printVector(tVector *v, void tPrint(void*)){
    int i = 0;
    for(i = 0; i < v->size; i++){
        tPrint(v->array[i]);
        printf(" ");
    }
    printf("\n");
}
void sortVector(tVector *v, int (*tCompare)(const void*, const void*), void (*tSwap)(void*, void*)){
    //qsort(v->array, v->size, sizeof(void*), tCompare)
    int i, j;
    for(i = 0; i < v->size - 1; i++){
        for(j = i + 1; j < v->size; j++){
            if(tCompare(v->array[i], v->array[j]) > 0){
                tSwap(v->array[i], v->array[j]);
            }
        }
    }
}
void freeVector(tVector *vec){
    int i;
    for(i = 0; i < vec->capacity; i++)
        free(vec->array[i]);
    free(vec->array);
    free(vec);
}