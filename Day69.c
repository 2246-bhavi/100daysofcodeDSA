#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

Node* adj[MAX];

Node* createNode(int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int u, int v, int w) {
    Node* newNode = createNode(v, w);
    newNode->next = adj[u];
    adj[u] = newNode;
}

void dijkstra(int n, int src) {
    int dist[MAX];
    int visited[MAX] = {0};

    for(int i=0;i<n;i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    for(int i=0;i<n-1;i++) {
        int min = INT_MAX, u;

        for(int j=0;j<n;j++) {
            if(!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        Node* temp = adj[u];
        while(temp) {
            int v = temp->vertex;
            int w = temp->weight;

            if(!visited[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }

            temp = temp->next;
        }
    }

    printf("Shortest distances from source %d:\n", src);
    for(int i=0;i<n;i++)
        printf("%d -> %d\n", i, dist[i]);
}

int main() {
    int n, m, u, v, w, src;

    scanf("%d", &n);
    scanf("%d", &m);

    for(int i=0;i<n;i++)
        adj[i] = NULL;

    for(int i=0;i<m;i++) {
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    scanf("%d", &src);

    dijkstra(n, src);

    return 0;
}