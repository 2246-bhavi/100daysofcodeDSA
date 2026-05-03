#include <stdio.h>
#include <stdlib.h>

// Node for linked list (bucket)
struct Node {
    float val;
    struct Node* next;
};

// Insert node at beginning
void insert(struct Node** head, float value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->val = value;
    temp->next = *head;
    *head = temp;
}

// Insertion sort on linked list
struct Node* sortList(struct Node* head) {
    struct Node* sorted = NULL;

    while(head != NULL) {
        struct Node* curr = head;
        head = head->next;

        if(sorted == NULL || curr->val < sorted->val) {
            curr->next = sorted;
            sorted = curr;
        } else {
            struct Node* temp = sorted;
            while(temp->next != NULL && temp->next->val < curr->val)
                temp = temp->next;

            curr->next = temp->next;
            temp->next = curr;
        }
    }
    return sorted;
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];
    for(int i = 0; i < n; i++)
        scanf("%f", &arr[i]);

    // Create buckets
    struct Node* buckets[n];
    for(int i = 0; i < n; i++)
        buckets[i] = NULL;

    // Distribute into buckets
    for(int i = 0; i < n; i++) {
        int idx = (int)(arr[i] * n);
        insert(&buckets[idx], arr[i]);
    }

    // Sort each bucket
    for(int i = 0; i < n; i++)
        buckets[i] = sortList(buckets[i]);

    // Concatenate buckets
    int k = 0;
    for(int i = 0; i < n; i++) {
        struct Node* temp = buckets[i];
        while(temp != NULL) {
            arr[k++] = temp->val;
            temp = temp->next;
        }
    }

    // Print sorted array
    for(int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);

    return 0;
}