#ifndef T_DOUBLE_H
#define T_DOUBLE_H

#define DEF_DOUBLE_VALUE 0.0

void* copyDouble(void *data);
int compareDouble(const void *a, const void *b);
void printDouble(void *data);
void swapDouble(void*, void*);
void* defaultDouble();
void copyDoubleTo(void *dest, void* source);

#endif
