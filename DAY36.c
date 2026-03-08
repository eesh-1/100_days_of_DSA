#include <stdio.h>

int main() {
    int n, m;

    // read number of elements
    scanf("%d", &n);

    int arr[n];

    // read elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // number of dequeue operations
    scanf("%d", &m);

    // circular shift of front
    int front = m % n;

    // print circular queue
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[(front + i) % n]);
    }

    return 0;
}
