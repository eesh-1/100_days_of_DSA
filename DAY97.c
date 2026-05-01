#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Interval;

int cmp(const void *a, const void *b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

// Min Heap
void heapify(int heap[], int n, int i) {
    int smallest = i;
    int l = 2*i + 1, r = 2*i + 2;

    if (l < n && heap[l] < heap[smallest]) smallest = l;
    if (r < n && heap[r] < heap[smallest]) smallest = r;

    if (smallest != i) {
        int t = heap[i]; heap[i] = heap[smallest]; heap[smallest] = t;
        heapify(heap, n, smallest);
    }
}

void insert(int heap[], int *size, int val) {
    heap[(*size)++] = val;
    int i = *size - 1;

    while (i > 0 && heap[(i-1)/2] > heap[i]) {
        int t = heap[i];
        heap[i] = heap[(i-1)/2];
        heap[(i-1)/2] = t;
        i = (i-1)/2;
    }
}

void removeMin(int heap[], int *size) {
    heap[0] = heap[--(*size)];
    heapify(heap, *size, 0);
}

int minRooms(Interval arr[], int n) {
    qsort(arr, n, sizeof(Interval), cmp);

    int heap[1000], size = 0;

    insert(heap, &size, arr[0].end);

    for (int i = 1; i < n; i++) {
        if (heap[0] <= arr[i].start) {
            removeMin(heap, &size);
        }
        insert(heap, &size, arr[i].end);
    }

    return size;
}

int main() {
    Interval arr[] = {{0,30},{5,10},{15,20}};
    int n = 3;

    printf("Minimum rooms = %d\n", minRooms(arr, n));
    return 0;
}
