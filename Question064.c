/*Problem: Perform BFS from a given source using queue.

Input:
- n
- adjacency list
- source s

Output:
- BFS traversal order*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100
struct Node {
    int data;
    struct Node* next;
};
struct Node* adj[MAX];
int queue[MAX];
int front = -1, rear = -1;
int visited[MAX];
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
    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}
void enqueue(int x) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = x;
}
int dequeue() {
    if (front == -1 || front > rear) {
        return -1;
    }
    return queue[front++];
}
void bfs(int n, int start) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    front = rear = -1;
    enqueue(start);
    visited[start] = 1;
    printf("BFS Traversal: ");
    while (front <= rear) {
        int current = dequeue();
        printf("%d ", current);
        struct Node* temp = adj[current];
        while (temp != NULL) {
            if (!visited[temp->data]) {
                enqueue(temp->data);
                visited[temp->data] = 1;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}
int main() {
    int n, e, u, v, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        adj[i] = NULL;
    printf("Enter number of edges: ");
    scanf("%d", &e);
    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    printf("Enter starting vertex: \n");
    scanf("%d", &start);
    bfs(n, start);
    return 0;
}