#ifndef T_VECTOR_H
#define T_VECTOR_H

typedef struct {
    int size;
    int capacity;
    void **array;
} tVector;
tVector* constructVector(int);
void insertVector(tVector*, void*, void* (*tCopy)(void*));
int changeValueByPosVector(tVector *v, int pos, void* data, void* (*tCopy)(void*), void (*tCopyTo)(void*, void*));
tVector* copyVector(tVector *v, void* (*tCopy) (void*));
void fillVector(tVector*, int, void* (*defaultValue)(), void* (*tCopy)(void*));

void sortVector(tVector *vec, void (*swap) (void*, void*), int (*comp)(const void *, const void *));

void printVector(tVector*, void (*tPrint)(void*));
void freeVector(tVector *v);

#endif