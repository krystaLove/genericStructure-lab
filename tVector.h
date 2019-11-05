typedef struct {
    int size;
    int capacity;
    void **array;
} tVector;
tVector* constructVector(int);
void insertVector(tVector*, void*, void* (*tCopy)(void*));
void printVector(tVector*, void (*tPrint)(void*));
void freeVector(tVector *v);
int changeValueByPosVector(tVector *v, int pos, void* data, void* (*tCopy)(void*));
tVector* copyVector(tVector *v, void* (*tCopy) (void*));