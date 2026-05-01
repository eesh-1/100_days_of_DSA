#include <stdio.h>

int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1, sum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxPages) return 0;

        if (sum + arr[i] > maxPages) {
            students++;
            sum = arr[i];
        } else {
            sum += arr[i];
        }
    }
    return students <= m;
}

int bookAllocation(int arr[], int n, int m) {
    int low = 0, high = 0, ans = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] > low) low = arr[i];
        high += arr[i];
    }

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(arr, n, m, mid)) {
            ans = mid;
            high = mid - 1; // minimize
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int arr[] = {12, 34, 67, 90};
    int n = 4, m = 2;

    printf("%d\n", bookAllocation(arr, n, m));
    return 0;
}
