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

void DFS(int v, int visited[], struct Node* adj[]) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = adj[v];

    while (temp != NULL) {
        int neighbor = temp->vertex;

        if (!visited[neighbor]) {
            DFS(neighbor, visited, adj);
        }

        temp = temp->next;
    }
}

int main() {

    int n, m;
    scanf("%d", &n);   // number of vertices
    scanf("%d", &m);   // number of edges

    struct Node* adj[n];

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    int u, v;

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        newNode = createNode(u);
        newNode->next = adj[v];
        adj[v] = newNode;
    }

    int s;
    scanf("%d", &s);   // starting vertex

    int visited[n];

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    DFS(s, visited, adj);

    return 0;
}