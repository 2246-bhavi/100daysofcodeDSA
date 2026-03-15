#include <stdio.h>
#include <string.h>

#define MAX 100

int dq[MAX];
int front = -1;
int rear = -1;

void push_front(int x)
{
    if(front == -1)
    {
        front = rear = 0;
        dq[front] = x;
    }
    else
    {
        front--;
        dq[front] = x;
    }
}

void push_back(int x)
{
    if(front == -1)
    {
        front = rear = 0;
        dq[rear] = x;
    }
    else
    {
        rear++;
        dq[rear] = x;
    }
}

void pop_front()
{
    if(front == -1 || front > rear)
    {
        printf("Deque Empty\n");
    }
    else
    {
        front++;
    }
}

void pop_back()
{
    if(front == -1 || front > rear)
    {
        printf("Deque Empty\n");
    }
    else
    {
        rear--;
    }
}

void show_front()
{
    if(front == -1 || front > rear)
        printf("-1\n");
    else
        printf("%d\n", dq[front]);
}

void show_back()
{
    if(front == -1 || front > rear)
        printf("-1\n");
    else
        printf("%d\n", dq[rear]);
}

void show_size()
{
    if(front == -1 || front > rear)
        printf("0\n");
    else
        printf("%d\n", rear - front + 1);
}

void is_empty()
{
    if(front == -1 || front > rear)
        printf("Empty\n");
    else
        printf("Not Empty\n");
}

void display()
{
    int i;
    for(i = front; i <= rear; i++)
        printf("%d ", dq[i]);
    printf("\n");
}

int main()
{
    int n, x;
    char op[20];

    printf("Enter number of operations:\n");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%s", op);

        if(strcmp(op,"push_front") == 0)
        {
            scanf("%d",&x);
            push_front(x);
        }

        else if(strcmp(op,"push_back") == 0)
        {
            scanf("%d",&x);
            push_back(x);
        }

        else if(strcmp(op,"pop_front") == 0)
            pop_front();

        else if(strcmp(op,"pop_back") == 0)
            pop_back();

        else if(strcmp(op,"front") == 0)
            show_front();

        else if(strcmp(op,"back") == 0)
            show_back();

        else if(strcmp(op,"size") == 0)
            show_size();

        else if(strcmp(op,"empty") == 0)
            is_empty();

        else if(strcmp(op,"display") == 0)
            display();
    }

    return 0;
}
