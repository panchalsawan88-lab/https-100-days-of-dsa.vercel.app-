/*Problem Statement
Using BFS or DFS, check if the entire graph is connected.

Input Format
n m
edges

Output Format
CONNECTED
NOT CONNECTED

Sample Input
4 2
1 2
3 4

Sample Output
NOT CONNECTED*/

#include <stdio.h>
#include <stdlib.h>

void dfs(int node, int* visited, int** adj, int* adjSize) {
    visited[node] = 1;
    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];
        if (!visited[neighbor]) {
            dfs(neighbor, visited, adj, adjSize);
        }
    }
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int** adj = (int**)malloc((n + 1) * sizeof(int*));
    int* adjSize = (int*)calloc(n + 1, sizeof(int));
    int u, v;
    int* degree = (int*)calloc(n + 1, sizeof(int));
    int edges[m][2];
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        edges[i][0] = u;
        edges[i][1] = v;
        degree[u]++;
        degree[v]++;
    }
    for (int i = 1; i <= n; i++) {
        adj[i] = (int*)malloc(degree[i] * sizeof(int));
    }
    for (int i = 0; i < m; i++) {
        u = edges[i][0];
        v = edges[i][1];

        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }
    int* visited = (int*)calloc(n + 1, sizeof(int));
    dfs(1, visited, adj, adjSize);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            printf("NOT CONNECTED\n");
            return 0;
        }
    }
    printf("CONNECTED\n");
    return 0;
}