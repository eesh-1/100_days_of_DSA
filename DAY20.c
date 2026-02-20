#include <stdio.h>
#include <stdlib.h>

#define MAX 1000001

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefix = 0;
    long long count = 0;

    // Offset to handle negative prefix sums
    int offset = MAX / 2;

    long long freq[MAX] = {0};

    freq[offset] = 1;   // prefix sum 0 initially

    for(int i = 0; i < n; i++) {
        prefix += arr[i];

        if(freq[prefix + offset] > 0) {
            count += freq[prefix + offset];
        }

        freq[prefix + offset]++;
    }

    printf("%lld\n", count);

    return 0;
}
