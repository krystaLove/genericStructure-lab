#include "tVector.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
        int i;
        for(i = v->capacity / 2; i < v->capacity; i++)
            v->array[i] = NULL;
    }
    v->array[v->size++] = tCopy(data);
}
void printVector(tVector *v, void (*tPrint)(void*)){
    int i = 0;
    for(i = 0; i < v->size; i++){
        if(v->array[i] == NULL){
            printf("NULL");
        } else {
            tPrint(v->array[i]);
        }

        printf(" ");
    }
}
tVector* copyVector(tVector *v, void* (*tCopy) (void*)){
    tVector *copy = constructVector(v->capacity);
    copy->size = v->size;
    copy->capacity = v->capacity;
    copy->array = calloc(sizeof(void*), v->capacity);
    int i;
    for(i = 0; i < v->size; i++)
        copy->array[i] = tCopy(v->array[i]);

    return copy;
}
int changeValueByPosVector(tVector *v, int pos, void* data, void* (*tCopy)(void*)){
    if(pos >= v->size) return -1;
    memcpy(v->array[pos], tCopy(data), sizeof(void*));
}
void freeVector(tVector *vec){
    int i;
    for(i = 0; i < vec->capacity; i++)
        free(vec->array[i]);
    free(vec->array);
    free(vec);
}