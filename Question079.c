/*Problem Statement
Find shortest distances from source vertex in a weighted graph with non-negative weights.

Input Format
n m
u v w
source

Output Format
Distances to all vertices.

Sample Input
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

Sample Output
0 2 3 9 6

Explanation
Shortest distances computed via priority queue.*/

#include <stdio.h>
#include <limits.h>
#define MAX 100
int minDistance(int dist[], int visited[], int n) {
    int min = INT_MAX, min_index = -1;

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}
void dijkstra(int graph[MAX][MAX], int n, int src) {
    int dist[MAX];
    int visited[MAX] = {0};
    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;
    for (int count = 1; count <= n - 1; count++) {
        int u = minDistance(dist, visited, n);
        visited[u] = 1;
        for (int v = 1; v <= n; v++) {
            if (!visited[v] && graph[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {                
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", dist[i]);
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int graph[MAX][MAX] = {0};
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // undirected
    }
    int src;
    scanf("%d", &src);
    dijkstra(graph, n, src);
    return 0;
}