/*Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 5   
struct Node {
    int vertex;
    int weight;
    struct Node* next;
};
struct Node* newNode(int v, int w) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->vertex = v;
    temp->weight = w;
    temp->next = NULL;
    return temp;
}
void addEdge(struct Node* adj[], int u, int v, int w) {
    struct Node* temp = newNode(v, w);
    temp->next = adj[u];
    adj[u] = temp;
}
struct MinHeapNode {
    int vertex;
    int dist;
};
struct MinHeap {
    int size;
    struct MinHeapNode heap[100];
};
void swap(struct MinHeapNode* a, struct MinHeapNode* b) {
    struct MinHeapNode t = *a;
    *a = *b;
    *b = t;
}
void heapify(struct MinHeap* pq, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if (left < pq->size && pq->heap[left].dist < pq->heap[smallest].dist)
        smallest = left;
    if (right < pq->size && pq->heap[right].dist < pq->heap[smallest].dist)
        smallest = right;
    if (smallest != i) {
        swap(&pq->heap[i], &pq->heap[smallest]);
        heapify(pq, smallest);
    }
}
struct MinHeapNode extractMin(struct MinHeap* pq) {
    struct MinHeapNode root = pq->heap[0];
    pq->heap[0] = pq->heap[pq->size - 1];
    pq->size--;
    heapify(pq, 0);
    return root;
}
void insert(struct MinHeap* pq, int v, int dist) {
    int i = pq->size++;
    pq->heap[i].vertex = v;
    pq->heap[i].dist = dist;
    while (i && pq->heap[(i - 1)/2].dist > pq->heap[i].dist) {
        swap(&pq->heap[i], &pq->heap[(i - 1)/2]);
        i = (i - 1)/2;
    }
}
void dijkstra(struct Node* adj[], int src) {
    int dist[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    struct MinHeap pq;
    pq.size = 0;
    dist[src] = 0;
    insert(&pq, src, 0);
    while (pq.size > 0) {
        struct MinHeapNode min = extractMin(&pq);
        int u = min.vertex;
        struct Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->vertex;
            int weight = temp->weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                insert(&pq, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d\t%d\n", i, dist[i]);
}
int main() {
    struct Node* adj[V];
    for (int i = 0; i < V; i++)
        adj[i] = NULL;
    addEdge(adj, 0, 1, 10);
    addEdge(adj, 0, 4, 5);
    addEdge(adj, 1, 2, 1);
    addEdge(adj, 4, 1, 3);
    addEdge(adj, 4, 2, 9);
    addEdge(adj, 2, 3, 4);
    addEdge(adj, 3, 0, 7);
    dijkstra(adj, 0);

    return 0;
}