#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Interval;

int cmp(const void *a, const void *b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

void mergeIntervals(Interval arr[], int n) {
    qsort(arr, n, sizeof(Interval), cmp);

    int index = 0;

    for (int i = 1; i < n; i++) {
        if (arr[index].end >= arr[i].start) {
            if (arr[i].end > arr[index].end)
                arr[index].end = arr[i].end;
        } else {
            index++;
            arr[index] = arr[i];
        }
    }

    for (int i = 0; i <= index; i++) {
        printf("[%d, %d] ", arr[i].start, arr[i].end);
    }
}

int main() {
    Interval arr[] = {{1,3},{2,6},{8,10},{15,18}};
    int n = 4;

    mergeIntervals(arr, n);
    return 0;
}
