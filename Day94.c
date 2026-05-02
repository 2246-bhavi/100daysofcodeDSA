#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    int max = 0;

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if(arr[i] > max)
            max = arr[i];
    }

    // Step 1: Frequency array
    int count[max + 1];
    for(int i = 0; i <= max; i++)
        count[i] = 0;

    for(int i = 0; i < n; i++)
        count[arr[i]]++;

    // Step 2: Prefix sum
    for(int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    // Step 3: Build output array (stable)
    int output[n];
    for(int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Step 4: Copy back
    for(int i = 0; i < n; i++)
        arr[i] = output[i];

    // Print sorted array
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}