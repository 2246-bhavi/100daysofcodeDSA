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

int DFS(int v, int visited[], int recStack[], struct Node* adj[]) {
    
    visited[v] = 1;
    recStack[v] = 1;

    struct Node* temp = adj[v];

    while (temp != NULL) {
        int neighbor = temp->vertex;

        if (!visited[neighbor] && DFS(neighbor, visited, recStack, adj))
            return 1;

        else if (recStack[neighbor])
            return 1;

        temp = temp->next;
    }

    recStack[v] = 0;
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
    }

    int visited[n], recStack[n];

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    int cycle = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (DFS(i, visited, recStack, adj)) {
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