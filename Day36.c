#include <stdio.h>

#define SIZE 100

int main()
{
    int q[SIZE];
    int n, m, i;
    int front = 0, rear = -1;

    printf("Enter number of elements:\n");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
    {
        rear = (rear + 1) % SIZE;
        scanf("%d", &q[rear]);
    }

    printf("Enter number of dequeue operations:\n");
    scanf("%d", &m);

    for(i = 0; i < m; i++)
    {
        front = (front + 1) % SIZE;
    }

    printf("Queue after operations:\n");

    int count = n;
    int index = front;

    for(i = 0; i < count; i++)
    {
        printf("%d ", q[index]);
        index = (index + 1) % SIZE;
    }

    return 0;
}