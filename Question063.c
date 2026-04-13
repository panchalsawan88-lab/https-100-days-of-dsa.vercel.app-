/*Problem: Perform DFS starting from a given source vertex using recursion.

Input:
- n
- adjacency list
- starting vertex s

Output:
- DFS traversal order*/

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}
void addEdge(struct Node* adj[], int u, int v) {
    struct Node* node = createNode(v);
    node->next = adj[u];
    adj[u] = node;
    node = createNode(u);
    node->next = adj[v];
    adj[v] = node;
}
void dfs(int node, struct Node* adj[], int visited[]) {
    visited[node] = 1;
    printf("%d ", node);
    struct Node* temp = adj[node];
    while (temp != NULL) {
        if (!visited[temp->data]) {
            dfs(temp->data, adj, visited);
        }
        temp = temp->next;
    }
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    struct Node* adj[n];
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
    }
    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }
    int s;
    scanf("%d", &s);  
    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    printf("DFS Traversal: ");
    dfs(s, adj, visited);
    return 0;
}