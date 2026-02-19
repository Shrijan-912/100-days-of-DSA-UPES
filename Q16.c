#include <stdio.h>

// Function to sort the array (simple bubble sort)
void sort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;

    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array
    sort(arr, n);

    int count = 1;

    for(int i = 1; i < n; i++) {
        if(arr[i] == arr[i - 1]) {
            count++;
        } else {
            printf("%d:%d ", arr[i - 1], count);
            count = 1;
        }
    }

    // Print frequency of last element
    if(n > 0)
        printf("%d:%d", arr[n - 1], count);

    return 0;
}