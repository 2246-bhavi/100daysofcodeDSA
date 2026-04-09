#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

int isEmpty() {
    return front > rear || front == -1;
}

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adj[MAX][MAX];
    int indegree[MAX] = {0};

    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
            if(adj[i][j] == 1)
                indegree[j]++;
        }
    }

    // Push vertices with indegree 0
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0)
            enqueue(i);
    }

    printf("Topological Order: ");

    while(!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);

        for(int i = 0; i < n; i++) {
            if(adj[node][i] == 1) {
                indegree[i]--;
                if(indegree[i] == 0)
                    enqueue(i);
            }
        }
    }

    printf("\n");

    return 0;
}