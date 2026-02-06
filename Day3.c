#include <stdio.h>
int main()
{
    int arr[100];
    int n, k, i, count = 0;
    int found = -1;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter key to search: ");
    scanf("%d", &k);

    for(i = 0; i < n; i++)
    {
        count++;

        if(arr[i] == k)
        {
            found = i;
            break;
        }
    }
    if(found != -1)
        printf("Found at index %d\n", found);
    else
        printf("Not Found\n");

    printf("Comparisons = %d", count);

    return 0;
}
