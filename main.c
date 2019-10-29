#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "tInteger.h"

int main() {
   Matrix *matrix = constructMatrix();
   int i, j;
   int cnt = 0;
   for(i = 0; i<5; i++){
       for(j = 0; j<5; j++){
            insertMatrix(matrix, &(cnt), i, copyInt);
            cnt++;
       }
   }
  // printMatrix(matrix, printInt);
    return 0;
}