//Given an array of integers, rotate the array to the right by k positions.

#include<stdio.h>
int main()
{
    int arr[100],temp[100];
    int n,k,i;
    printf("enter number of elements:");
    scanf("%d",&n);

    printf("enter array elements:\n");
    for(i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter value of k:");
    scanf("%d",&k);

    k=k%n;
    for(i=0; i<k; i++)
    {
        temp[i]=arr[n-k+i];
    }
    for(i=0; i<n-k; i++)
    {
        temp[k+i]=arr[i];
    }
    printf("Array after rotation:\n");
    for(i=0; i<n; i++)
    {
        printf("%d ",temp[i]);
    }
    return 0;
}
