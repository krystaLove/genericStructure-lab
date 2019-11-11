#include <stdio.h>
#include <stdlib.h>

#include "tVector.h"
#include "tMatrix.h"

#include "tInteger.h"
#include "tDouble.h"

void vectorTrial2(){
    tVector *vec = constructVector(8);
    int cnt = 5;
    fillVector(vec, 7, defaultInt, copyInt);
    changeValueByPosVector(vec, 2, &cnt, copyInt, freeInt);
    cnt = 11;
    changeValueByPosVector(vec, 1, &cnt, copyInt, freeInt);
    sortVector(vec, compareInt);
;
    printVector(vec, printInt);

    freeVector(vec, freeInt);
}
void matrixTrial(){

    tMatrix *matrix = constructMatrix(5, defaultDouble, freeDouble);
    tVector *vector = constructVector(8);

    int i;
    int cnt = 0;
    int j;
    for(i = 0; i < 6; i++){
        for(j = 0; j < 2; j++){
            double randomValue = 1.0 * (rand() % 150) - (rand() % 32);
            insertMatrix(matrix, &randomValue, i, j, copyDouble);
            cnt++;
        }
    }
    for(i = 0; i < 5; i++){
        double data = i * 1337;
        insertVector(vector, &data, copyDouble);
    }
    double data = 1337;
    insertMatrix(matrix, &data, 3, 3, copyDouble);
    insertMatrix(matrix, &data, 6, 0, copyDouble);
    sortMatrix(matrix, compareDouble);
    addVectorToMatrix(matrix, vector, copyDouble);
    printf("%d %d\n", matrix->n, matrix->m);
    printMatrix(matrix, printDouble);

    freeMatrix(matrix);
    freeVector(vector, freeDouble);

}
int main() {
    //matrixTrial();
    //vectorTrial2();
    charTrial();
    return 0;
}