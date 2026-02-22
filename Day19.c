//Given an array of integers, find two elements whose sum is closest to zero.

#include<stdio.h>
int main()
{
    int arr[100];
    int n,i,j;
    int minSum,sum;
    int x,y;
    int minvalue,currentvalue;
    printf("Enter number of elements:");
    scanf("%d",&n);
    printf("Enter array elements:\n");
    for(i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    minSum=arr[0]+arr[1];
    if(minSum<0)
    {
        minvalue=-minSum;
    }
    else
    {
        minvalue=minSum;
    }
    x=arr[0];
    y=arr[1];
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            sum=arr[i]+arr[j];
            if(sum<0)
            {
                currentvalue=-sum;
            }
            else
            {
                currentvalue=sum;
            }
            if(currentvalue<minvalue)
            {
                minvalue=currentvalue;
                x=arr[i];
                y=arr[j];
            }

        }
    }
    printf("the elements are:%d %d",x,y);
    return 0;
}