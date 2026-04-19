#include <stdio.h>
#define MAX 100
#define INF 999999

int main() {
    int n, m;
    int graph[MAX][MAX];
    int visited[MAX] = {0};

    scanf("%d %d", &n, &m);

    // Initialize graph with INF
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            graph[i][j] = INF;

    // Read edges
    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    visited[1] = 1;
    int edges = 0;
    int totalWeight = 0;

    while(edges < n - 1) {
        int min = INF, x = 0, y = 0;

        for(int i = 1; i <= n; i++) {
            if(visited[i]) {
                for(int j = 1; j <= n; j++) {
                    if(!visited[j] && graph[i][j] < min) {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        visited[y] = 1;
        totalWeight += graph[x][y];
        edges++;
    }

    printf("%d", totalWeight);

    return 0;
}