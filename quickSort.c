static int HoarPartition(void** arr, int l, int r, int (*comp)(const void*, const void*)){
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
        if(i > j) return j;

        void *tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

void quickSort(void** arr, int l, int r, int (*comp)(const void*, const void*)){
    int pivot;
    if(l < r){
        pivot = HoarPartition(arr, l, r, comp);
        quickSort(arr, l, pivot - 1, comp);
        quickSort(arr, pivot + 1, r, comp);
    }
}