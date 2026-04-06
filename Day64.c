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

int queue[100];
int front = 0, rear = -1;

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

void BFS(int s, int visited[], struct Node* adj[]) {

    enqueue(s);
    visited[s] = 1;

    while (!isEmpty()) {

        int v = dequeue();
        printf("%d ", v);

        struct Node* temp = adj[v];

        while (temp != NULL) {
            int neighbor = temp->vertex;

            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                enqueue(neighbor);
            }

            temp = temp->next;
        }
    }
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

    int s;
    scanf("%d", &s);

    int visited[n];

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    BFS(s, visited, adj);

    return 0;
}