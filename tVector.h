#ifndef T_VECTOR_H
#define T_VECTOR_H

typedef struct {
    int size;
    int capacity;
    void **array;
} tVector;
tVector* constructVector(int);
void insertVector(tVector*, void*, void* (*tCopy)(void*));
int changeValueByPosVector(tVector *v, int pos, void* data, void* (*tCopy)(void*), void (*tFree)(void*));
tVector* copyVector(tVector *v, void* (*tCopy) (void*));
void fillVector(tVector*, int, void* (*defaultValue)(), void* (*tCopy)(void*));

void sortVector(tVector *vec, int (*comp)(const void *, const void *));

void printVector(tVector*, void (*tPrint)(void*));
void freeVector(tVector *v, void (*tFree)(void*));

#endif