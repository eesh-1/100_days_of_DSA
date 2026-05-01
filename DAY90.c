#include <stdio.h>

int isValid(int boards[], int n, int k, int maxTime) {
    int painters = 1, sum = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > maxTime) return 0;

        if (sum + boards[i] > maxTime) {
            painters++;
            sum = boards[i];
        } else {
            sum += boards[i];
        }
    }
    return painters <= k;
}

int painterPartition(int boards[], int n, int k) {
    int low = 0, high = 0, ans = -1;

    for (int i = 0; i < n; i++) {
        if (boards[i] > low) low = boards[i];
        high += boards[i];
    }

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isValid(boards, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int boards[] = {10, 20, 30, 40};
    int n = 4, k = 2;

    printf("%d\n", painterPartition(boards, n, k));
    return 0;
}
