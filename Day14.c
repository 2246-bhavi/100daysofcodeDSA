//Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.

#include <stdio.h>

int main()
{
    int a[10][10];
    int n, i, j;
    int ok = 1;

    printf("Enter size of matrix: ");
    scanf("%d", &n);

    printf("Enter matrix elements:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i == j && a[i][j] != 1)
            {
                ok = 0;
                break;
            }
            if(i != j && a[i][j] != 0)
            {
                ok = 0;
                break;
            }
        }
        if(ok == 0)
            break;
    }

    if(ok == 1)
        printf("Identity Matrix");
    else
        printf("Not an Identity Matrix");

    return 0;
}
