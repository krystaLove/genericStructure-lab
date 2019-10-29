#include <stdio.h>
#include <stdlib.h>

#include "tMatrix.h"
#include "tInteger.h"
#include "quickSort.h"

int main() {
    int i;

    tVector *vec = constructVector(8);
    i = 5;
    insertVector(vec, &i, copyInt);
    i = 1;
    insertVector(vec, &i, copyInt);
    i = 1;
    insertVector(vec, &i, copyInt);
    i = 0;
    insertVector(vec, &i, copyInt);
    for(i = 10; i>0; i--) insertVector(vec, &i, copyInt);

    printVector(vec, printInt);

    qsort(vec->array, vec->size, sizeof(void*), compareInt);
    printVector(vec, printInt);

    quickSort(vec->array, 0, vec->size - 1, swapInt, compareInt);
    printVector(vec, printInt);

    freeVector(vec);

    return 0;
}