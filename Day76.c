#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int val;
    int numNeighbors;
    struct Node* neighbors[MAX];
};

struct Node* visited[MAX];

struct Node* cloneGraph(struct Node* node) {
    if (node == NULL)
        return NULL;

    if (visited[node->val] != NULL)
        return visited[node->val];

    struct Node* clone = (struct Node*)malloc(sizeof(struct Node));
    clone->val = node->val;
    clone->numNeighbors = node->numNeighbors;

    visited[node->val] = clone;

    for (int i = 0; i < node->numNeighbors; i++) {
        clone->neighbors[i] = cloneGraph(node->neighbors[i]);
    }

    return clone;
}