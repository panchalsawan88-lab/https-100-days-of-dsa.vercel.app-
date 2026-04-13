/*Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100
struct Node {
    int data;
    struct Node* next;
};
struct Node* adj[MAX];
int visited[MAX];
int recStack[MAX];
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void addEdge(int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}
int dfs(int node) {
    visited[node] = 1;
    recStack[node] = 1;
    struct Node* temp = adj[node];
    while (temp != NULL) {
        int neighbor = temp->data;
        if (!visited[neighbor]) {
            if (dfs(neighbor))
                return 1;
        }
        else if (recStack[neighbor]) {
            return 1; // Cycle found
        }
        temp = temp->next;
    }
    recStack[node] = 0; // backtrack
    return 0;
}
int hasCycle(int n) {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i))
                return 1;
        }
    }
    return 0;
}
int main() {
    int n, e, u, v;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        adj[i] = NULL;
    printf("Enter number of edges: ");
    scanf("%d", &e);
    printf("Enter directed edges (u v):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    if (hasCycle(n))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}