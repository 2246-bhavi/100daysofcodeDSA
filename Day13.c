//you are given a rectangular matrix of integers. Starting from the outer boundary, traverse the matrix in a clockwise manner and continue moving inward layer by layer until all elements are visited.

#include <stdio.h>

int main()
{
    int a[20][20];
    int r, c, i, j;
    int top, bottom, left, right;

    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter matrix elements:\n");
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    top = 0;
    bottom = r - 1;
    left = 0;
    right = c - 1;

    while(top <= bottom && left <= right)
    {
        for(j = left; j <= right; j++)
            printf("%d ", a[top][j]);
        top++;

        for(i = top; i <= bottom; i++)
            printf("%d ", a[i][right]);
        right--;

        if(top <= bottom)
        {
            for(j = right; j >= left; j--)
                printf("%d ", a[bottom][j]);
            bottom--;
        }

        if(left <= right)
        {
            for(i = bottom; i >= top; i--)
                printf("%d ", a[i][left]);
            left++;
        }
    }

    return 0;
}
