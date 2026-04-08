#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void topologicalSortUtil(int v, int visited[], struct Node* adj[], int stack[], int* top) {
    visited[v] = 1;

    struct Node* temp = adj[v];

    while (temp != NULL) {
        int neighbor = temp->vertex;
        if (!visited[neighbor])
            topologicalSortUtil(neighbor, visited, adj, stack, top);
        temp = temp->next;
    }

    stack[(*top)++] = v;  // push vertex to stack after visiting neighbors
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m); // vertices and edges

    struct Node* adj[n];
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v); // directed edge u -> v
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;
    }

    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int stack[n];
    int top = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i])
            topologicalSortUtil(i, visited, adj, stack, &top);
    }

    // print topological order (stack in reverse)
    for (int i = top - 1; i >= 0; i--)
        printf("%d ", stack[i]);

    return 0;
}