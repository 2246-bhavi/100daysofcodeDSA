#include <stdio.h>
#include <string.h>

int main()
{
    int pq[100];
    int size = 0;
    int n, i, j;
    char op[10];
    int x;

    printf("Enter number of operations:\n");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%s", op);

        if(strcmp(op, "insert") == 0)
        {
            scanf("%d", &x);
            pq[size] = x;
            size++;

            for(j = size - 1; j > 0; j--)
            {
                if(pq[j] < pq[j-1])
                {
                    int temp = pq[j];
                    pq[j] = pq[j-1];
                    pq[j-1] = temp;
                }
            }
        }

        else if(strcmp(op, "delete") == 0)
        {
            if(size == 0)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", pq[0]);

                for(j = 0; j < size - 1; j++)
                {
                    pq[j] = pq[j+1];
                }

                size--;
            }
        }

        else if(strcmp(op, "peek") == 0)
        {
            if(size == 0)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", pq[0]);
            }
        }
    }

    return 0;
}