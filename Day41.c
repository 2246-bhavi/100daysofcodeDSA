#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int x)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    if(front == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

int dequeue()
{
    if(front == NULL)
        return -1;

    struct Node *temp = front;
    int val = temp->data;

    front = front->next;

    if(front == NULL)
        rear = NULL;

    free(temp);

    return val;
}

int main()
{
    int n, x;
    char op[20];

    printf("Enter number of operations:\n");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("Enter operation (enqueue/dequeue):\n");
        scanf("%s", op);

        if(strcmp(op,"enqueue") == 0)
        {
            printf("Enter value to enqueue:\n");
            scanf("%d",&x);
            enqueue(x);
        }
        else if(strcmp(op,"dequeue") == 0)
        {
            int val = dequeue();
            printf("%d\n", val);
        }
    }

    return 0;
}