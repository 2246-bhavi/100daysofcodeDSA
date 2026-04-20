#include <stdio.h>
#define MAX 100
#define INF 999999

int main() {
    int n, m;
    int graph[MAX][MAX];
    int dist[MAX];
    int visited[MAX] = {0};

    scanf("%d %d", &n, &m);

    // Initialize graph
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            graph[i][j] = INF;

    // Read edges
    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;  // remove this line if graph is directed
    }

    int source;
    scanf("%d", &source);

    // Initialize distances
    for(int i = 1; i <= n; i++)
        dist[i] = INF;

    dist[source] = 0;

    for(int count = 1; count <= n; count++) {
        int min = INF, u = -1;

        // find vertex with minimum distance
        for(int i = 1; i <= n; i++) {
            if(!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        // update neighbors
        for(int v = 1; v <= n; v++) {
            if(!visited[v] && graph[u][v] != INF) {
                if(dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    // print distances
    for(int i = 1; i <= n; i++)
        printf("%d ", dist[i]);

    return 0;
}