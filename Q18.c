#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int k;
    scanf("%d", &k);

    k = k % n;  // handle k > n

    int temp[k];

    // store last k elements
    for(int i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    }

    // shift remaining elements right
    for(int i = n - 1; i >= k; i--) {
        arr[i] = arr[i - k];
    }

    // copy temp elements to front
    for(int i = 0; i < k; i++) {
        arr[i] = temp[i];
    }

    // print result
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}