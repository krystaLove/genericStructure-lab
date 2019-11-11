#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "tDouble.h"

#define EPS 1e-5

void* copyDouble(void *data){
    double *a = (double*) calloc(1, sizeof(double));
    *a = *((double*) data);
    return a;
}
int compareDouble(const void *a, const void *b){
    double first = *(double*)a;
    double second = *(double*)b;

    if(fabs(first - second) < EPS) return 0;

    if(first < second) return -1;

    return 1;
}
void printDouble(void *a){
    printf("%f", *((double*) a));
}
void swapDouble(void *a, void *b){
    void *c = malloc(sizeof(void*));
    memcpy(c, a, sizeof(double));
    memcpy(a, b, sizeof(double));
    memcpy(b, c, sizeof(double));
    free(c);
}
void* defaultDouble(){
    double *a = malloc(sizeof(double));
    *a = DEF_DOUBLE_VALUE;
    return a;
}

void copyDoubleTo(void *dest, void* source){
    memcpy((double*) dest, (double*) source, sizeof(double));
}
void freeDouble(void *data){
    free((double*)data);
}
