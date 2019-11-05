#ifndef T_MY_QUICKSORT
#define T_MY_QUICKSORT

void quickSort(void** arr, int l, int r, void (*swap)(void*, void*), int (*comp)(const void*, const void*));

#endif