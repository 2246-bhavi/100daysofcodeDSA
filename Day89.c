#include <stdio.h>

// Check if allocation is possible with maxPages
int canAllocate(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int pages = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] > maxPages)
            return 0;

        if(pages + arr[i] <= maxPages) {
            pages += arr[i];
        } else {
            students++;
            pages = arr[i];
        }
    }

    return (students <= m);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n];
    int sum = 0, maxVal = 0;

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
        if(arr[i] > maxVal)
            maxVal = arr[i];
    }

    int low = maxVal, high = sum, ans = sum;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(canAllocate(arr, n, m, mid)) {
            ans = mid;
            high = mid - 1;   // try smaller
        } else {
            low = mid + 1;    // increase limit
        }
    }

    printf("%d", ans);

    return 0;
}