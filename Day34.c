#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int pop()
{
    if(top == NULL)
    {
        printf("Stack Underflow\n");
        return 0;
    }

    struct Node *temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    return value;
}

int main()
{
    int a, b, result;
    char token;

    printf("Enter postfix expression:\n");

    while(scanf(" %c", &token) != EOF)
    {
        if(token >= '0' && token <= '9')
        {
            push(token - '0');
        }
        else if(token == '+' || token == '-' || token == '*' || token == '/')
        {
            b = pop();
            a = pop();

            if(token == '+')
                result = a + b;
            else if(token == '-')
                result = a - b;
            else if(token == '*')
                result = a * b;
            else if(token == '/')
                result = a / b;

            push(result);
        }
    }

    printf("Result = %d", pop());

    return 0;
}