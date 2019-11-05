#ifndef T_INTEGER_H
#define T_INTEGER_H

#define DEF_INT_VALUE 0

void* copyInt(void *data);
int compareInt(const void *a, const void *b);
void printInt(void *data);
void swapInt(void*, void*);
void* defaultInt();
void copyIntTo(void *dest, void* source);

#endif