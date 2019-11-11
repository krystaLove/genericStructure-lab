#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "tInteger.h"

void* copyInt(void *data){
    int *a = (int*) calloc(1, sizeof(int));
    *a = *((int*) data);
    return a;
}
int compareInt(const void *a, const void *b){
    return *((int*) a) - *((int*) b);
}
void printInt(void *a){
    printf("%d", *((int*) a));
}
void swapInt(void *a, void *b){
    void *c = malloc(sizeof(void*));
    memcpy(c, a, sizeof(int));
    memcpy(a, b, sizeof(int));
    memcpy(b, c, sizeof(int));
    free(c);
}
void* defaultInt(){
    int *a = malloc(sizeof(int));
    *a = DEF_INT_VALUE;
    return a;
}

void copyIntTo(void *dest, void* source){
    memcpy((int*) dest, (int*) source, sizeof(int));
}
void freeInt(void* data){
    free((int*)data);
}