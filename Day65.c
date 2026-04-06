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

int DFS(int v, int visited[], int parent, struct Node* adj[]) {
    
    visited[v] = 1;
    struct Node* temp = adj[v];

    while (temp != NULL) {
        int neighbor = temp->vertex;

        if (!visited[neighbor]) {
            if (DFS(neighbor, visited, v, adj))
                return 1;
        }
        else if (neighbor != parent) {
            return 1;
        }

        temp = temp->next;
    }

    return 0;
}

int main() {

    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

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

    int visited[n];

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int cycle = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (DFS(i, visited, -1, adj)) {
                cycle = 1;
                break;
            }
        }
    }

    if (cycle)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}