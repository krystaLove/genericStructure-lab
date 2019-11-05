#include <stdio.h>
#include <stdlib.h>

#include "tMatrix.h"
#include "tInteger.h"
#include "quickSort.h"

void vectorTrial(){
    tVector *vec = constructVector(8);
    int i;
    for(i = 10; i > 0; i--) insertVector(vec, &i, copyInt);
    int change = 27;
    printVector(vec, printInt);

    tVector *copy = copyVector(vec, copyInt);

    qsort(vec->array, vec->size, sizeof(void*), compareInt);
    printVector(vec, printInt);

    quickSort(vec->array, 0, vec->size - 1, swapInt, compareInt);
    printVector(vec, printInt);
    printVector(copy, printInt);

    freeVector(vec);
}
void vectorTrial2(){
    tVector *vec = constructVector(8);
}
void matrixTrial(){
    tMatrix *matrix = constructMatrix(5);
    tVector *vec = constructVector(6);
    int i;
    for(i = 5; i > 0; i--) insertVector(vec, &i, copyInt);

    addVectorToMatrix(matrix, vec, copyInt);
    quickSort(vec->array, 0, vec->size - 1, swapInt, compareInt);
    addVectorToMatrix(matrix, vec, copyInt);
    addVectorToMatrix(matrix, vec, copyInt);
    addRowMatrix(matrix);
    printf("%d %d\n", matrix->n, matrix->m);
    int change = 15;
    insertMatrix(matrix, &change, 0, 2, copyInt);
    for(i = 0; i < 10; i++) addVectorToMatrix(matrix, vec, copyInt);
    printMatrix(matrix, printInt);
}
int main() {
    matrixTrial();
    vectorTrial2();
    return 0;
}