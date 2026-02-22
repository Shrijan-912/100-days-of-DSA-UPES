#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    long long count = 0;
    long long prefixSum = 0;

    // Using simple hash via large array (for competitive programming style)
    // For safety in real cases, use unordered_map in C++.
    int size = 2 * n + 1;
    long long *freq = calloc(size, sizeof(long long));
    int offset = n;  // shift index to avoid negative indexing

    freq[offset] = 1;  // prefix sum 0 initially

    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if(prefixSum + offset >= 0 && prefixSum + offset < size) {
            count += freq[prefixSum + offset];
            freq[prefixSum + offset]++;
        }
    }

    printf("%lld\n", count);

    free(freq);
    return 0;
}