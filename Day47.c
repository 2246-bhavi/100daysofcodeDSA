#include <stdio.h>
#include <stdlib.h>

// Structure for tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to calculate height of tree
int height(struct Node* root) {
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}

// Insert nodes in level order
struct Node* buildTree(int arr[], int n, int i) {
    if (i >= n || arr[i] == -1)
        return NULL;

    struct Node* root = createNode(arr[i]);
    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);

    return root;
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter level order traversal (-1 for NULL): ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n, 0);

    printf("Height of the tree: %d\n", height(root));

    return 0;
}