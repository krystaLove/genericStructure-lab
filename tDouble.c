#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "tDouble.h"

void* copyDouble(void *data){
    double *a = (double*) calloc(1, sizeof(double));
    *a = *((double*) data);
    return a;
}
int compareDouble(const void *a, const void *b){
    return *((double*) a) - *((double*) b);
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
