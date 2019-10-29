typedef struct {
    int size;
    int capacity;
    void **array;
} tVector;
tVector* constructVector(int);
void insertVector(tVector*, void*, void* (*tCopy)(void*));
void printVector(tVector*, void (*tPrint)(void*));
void sortVector(tVector*, int (*tCompare)(const void*, const void*), void (*tSwap)(void*, void*));
void freeVector(tVector *v);