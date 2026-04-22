/*Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;
void enqueue(int x) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}
int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}
int isEmpty() {
    return (front == -1 || front > rear);
}
void topologicalSort(int n, int adj[MAX][MAX]) {
    int indegree[MAX] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }
    int count = 0;
    int topo[MAX];
    while (!isEmpty()) {
        int node = dequeue();
        topo[count++] = node;
        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    enqueue(i);
                }
            }
        }
    }
    if (count != n) {
        printf("Graph has a cycle! Topological sort not possible.\n");
        return;
    }
    printf("Topological Order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", topo[i]);
    }
    printf("\n");
}
int main() {
    int n, adj[MAX][MAX];
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    topologicalSort(n, adj);
    return 0;
}