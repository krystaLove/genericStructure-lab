#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
    memcpy(c, a, sizeof(void *));
    memcpy(a, b, sizeof(void*));
    memcpy(b, c, sizeof(void*));

}