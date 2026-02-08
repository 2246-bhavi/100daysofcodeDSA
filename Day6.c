//Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

#include <stdio.h>

int main()
{
    int arr[100];
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter sorted array elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Unique elements:\n");

    if(n > 0)
    {
        printf("%d ", arr[0]);

        for(i = 1; i < n; i++)
        {
            if(arr[i] != arr[i - 1])
            {
                printf("%d ", arr[i]);
            }
        }
    }

    return 0;
}
