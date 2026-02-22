//Count Nodes in Linked List

#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
int main()
{
    int n,i,count=0;
    struct Node *head = NULL, *temp = NULL,*newNode = NULL;
    printf("Enter number of elements:");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        newNode=(struct Node*)malloc(sizeof(struct Node));
        scanf("%d",&newNode->data);
        newNode->next=NULL;
        if(head==NULL)
        {
            head=newNode;
        }
        else{
            temp->next=newNode;
        }
        temp=newNode;
        }
        temp=head;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        printf("Number of nodes in the linked list:%d",count);
        return 0;
}
