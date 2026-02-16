#include <stdio.h>

int main()
{
    int a[10][10];
    int m, n, i, j;
    int sum = 0;

    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);

    printf("Enter matrix elements:\n");
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for(i = 0; i < m && i < n; i++)
    {
        sum = sum + a[i][i];
    }

    printf("%d", sum);

    return 0;
}
