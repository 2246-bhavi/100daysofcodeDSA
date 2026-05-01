#include <stdio.h>

// Check if painting is possible within maxTime
int canPaint(int arr[], int n, int k, int maxTime) {
    int painters = 1;
    int total = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] > maxTime)
            return 0;

        if(total + arr[i] <= maxTime) {
            total += arr[i];
        } else {
            painters++;
            total = arr[i];
        }
    }

    return (painters <= k);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

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

        if(canPaint(arr, n, k, mid)) {
            ans = mid;
            high = mid - 1;   // try smaller time
        } else {
            low = mid + 1;    // increase time
        }
    }

    printf("%d", ans);

    return 0;
}