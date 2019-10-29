typedef struct tVector{
    int size;
    int capacity;
    void **array;
} Vector;
Vector* constructVector();
void insertVector(Vector*, void*, void* (*tCopy)(void*));
void printVector(Vector *v, void (*tPrint)(void*));
void sortVector(Vector *v, int (*tCompare)(const void*, const void*), void (*tSwap)(void*, void*));