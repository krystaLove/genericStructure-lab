#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "tVector.h"
#include "quickSort.h"

tVector* constructVector(int startCapacity){
    tVector* vector = (tVector*) malloc(sizeof(tVector));
    vector->capacity = startCapacity;
    vector->size = 0;
    vector->array = calloc(sizeof(void*), vector->capacity);

    return vector;
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
        tPrint(v->array[i]);
        printf(" ");
    }
}
void fillVector(tVector *v, int howMany, void* (*defaultValue)(), void* (*tCopy)(void*)){
    int i;
    void *defValue = defaultValue();
    for(i = 0; i < howMany; i++){
        insertVector(v, defValue, tCopy);
    }
    free(defValue);
}
tVector* copyVector(tVector *v, void* (*tCopy) (void*)){
    tVector *copy = (tVector*) malloc(sizeof(tVector));
    copy->size = v->size;
    copy->capacity = v->capacity;
    copy->array = calloc(sizeof(void*), v->capacity);
    int i;
    for(i = 0; i < v->size; i++)
        copy->array[i] = tCopy(v->array[i]);

    return copy;
}
int changeValueByPosVector(tVector *v, int pos, void* data, void* (*tCopy)(void*), void (*tCopyTo)(void*, void*)){
    if(pos >= v->size) return -1;
    void* copy = tCopy(data);
    if(v->array[pos] == NULL)
        v->array[pos] = tCopy(data);
    else
        tCopyTo(v->array[pos], copy);
    free(copy);
}
void freeVector(tVector *vec){
    int i;
    for(i = 0; i < vec->capacity; i++)
        free(vec->array[i]);
    free(vec->array);
    free(vec);
}
void sortVector(tVector *vec, void (*swap) (void*, void*), int (*comp)(const void *, const void *)){
    quickSort(vec->array, 0, vec->size - 1, swap, comp);
}