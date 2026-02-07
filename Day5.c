/*A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.*/

#include <stdio.h>

int main()
{
    int log1[100], log2[100], merged[200];
    int p, q, i, j, k;

    printf("Enter number of entries in server log 1: ");
    scanf("%d", &p);

    printf("Enter sorted arrival times from server 1:\n");
    for(i = 0; i < p; i++)
        scanf("%d", &log1[i]);

    printf("Enter number of entries in server log 2: ");
    scanf("%d", &q);

    printf("Enter sorted arrival times from server 2:\n");
    for(i = 0; i < q; i++)
        scanf("%d", &log2[i]);

    i = 0; 
    j = 0; 
    k = 0;

    while(i < p && j < q)
    {
        if(log1[i] <= log2[j])
            merged[k++] = log1[i++];
        else
            merged[k++] = log2[j++];
    }

    while(i < p)
        merged[k++] = log1[i++];

    while(j < q)
        merged[k++] = log2[j++];

    printf("Merged chronological log:\n");
    for(i = 0; i < k; i++)
        printf("%d ", merged[i]);

    return 0;
}
