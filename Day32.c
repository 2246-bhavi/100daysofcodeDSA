#include <stdio.h>

int main()
{
    int stack[100];
    int n, m, i;
    int top = -1;

    printf("Enter number of elements to push:\n");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &stack[++top]);
    }

    printf("Enter number of pops:\n");
    scanf("%d", &m);

    for(i = 0; i < m; i++)
    {
        if(top == -1)
        {
            printf("Stack Underflow\n");
            break;
        }
        top--;
    }

    printf("Remaining stack elements (top to bottom):\n");
    for(i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }

    return 0;
}