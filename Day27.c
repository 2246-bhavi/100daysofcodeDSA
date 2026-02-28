//Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* createList(int n)
{
    struct Node *head = NULL, *temp = NULL, *newNode;
    int i;

    for(i = 0; i < n; i++)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    return head;
}

int main()
{
    int n, m;
    struct Node *head1, *head2;
    struct Node *temp1, *temp2;
    int found = 0;

    printf("Enter number of nodes in first list:\n");
    scanf("%d", &n);

    printf("Enter elements of first list:\n");
    head1 = createList(n);

    printf("Enter number of nodes in second list:\n");
    scanf("%d", &m);

    printf("Enter elements of second list:\n");
    head2 = createList(m);

    temp1 = head1;

    while(temp1 != NULL)
    {
        temp2 = head2;

        while(temp2 != NULL)
        {
            if(temp1->data == temp2->data)
            {
                printf("Intersection point value: %d\n", temp1->data);
                found = 1;
                break;
            }
            temp2 = temp2->next;
        }

        if(found == 1)
            break;

        temp1 = temp1->next;
    }

    if(found == 0)
    {
        printf("No Intersection\n");
    }

    return 0;
}
