#include "vector.h"
#include <stdlib.h>
#include <stdio.h>
Vector* constructVector(){
    Vector* vector = (Vector*) malloc(sizeof(Vector));
    vector->capacity = 8;
    vector->size = 0;
    vector->array = calloc(sizeof(void*), vector->capacity);
}

void insertVector(Vector *v, void* data, void* (*tCopy)(void*)){
    if(v->size + 1 > v->capacity){
        v->capacity *= 2;
        v->array = realloc(v->array, v->capacity * sizeof(void*));
    }
    v->array[v->size++] = tCopy(data);
}
void printVector(Vector *v, void tPrint(void*)){
    int i = 0;
    for(i = 0; i < v->size; i++){
        tPrint(v->array[i]);
        printf(" ");
    }
    printf("\n");
}
void sortVector(Vector *v, int (*tCompare)(const void*, const void*), void (*tSwap)(void*, void*)){
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