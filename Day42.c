#include <stdio.h>

int main()
{
    int queue[100];
    int stack[100];
    int n, i;

    printf("Enter number of elements:\n");
    scanf("%d", &n);

    printf("Enter queue elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &queue[i]);
    }

    for(i = 0; i < n; i++)
    {
        stack[i] = queue[i];
    }

    printf("Reversed queue:\n");

    for(i = n-1; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }

    return 0;
}