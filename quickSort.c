static int HoarPartition(void** arr, int l, int r, void (*swap)(void*, void*), int (*comp)(const void*, const void*)){
    void *x = arr[(l + r)/2];
    int i = l - 1;
    int j = r + 1;
    while(1){
        do{
            i = i + 1;
        } while(comp(arr[i], x) < 0);
        do {
            j = j - 1;
        } while(comp(arr[j], x) > 0);
        if(i >= j) return j;

        swap(arr[i], arr[j]);
    }
}

void quickSort(void** arr, int l, int r, void (*swap)(void*, void*), int (*comp)(const void*, const void*)){
    int pivot;
    if(l < r){
        pivot = HoarPartition(arr, l, r, swap, comp);
        quickSort(arr, l, pivot - 1, swap, comp);
        quickSort(arr, pivot + 1, r, swap, comp);
    }
}