/*Problem Statement:
Check whether a given binary tree satisfies the Min-Heap property.

Input Format:
- First line contains integer N
- Second line contains level-order traversal

Output Format:
- Print YES if valid Min-Heap, otherwise NO

Example:
Input:
7
1 3 5 7 9 8 10

Output:
YES

Explanation:
Each parent node must be smaller than its children.*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;
    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int front = 0, rear = 0;
    struct Node* root = createNode(arr[0]);
    queue[rear++] = root;
    int i = 1;
    while (i < n) {
        struct Node* temp = queue[front++];
        if (i < n) {
            temp->left = createNode(arr[i++]);
            queue[rear++] = temp->left;
        }
        if (i < n) {
            temp->right = createNode(arr[i++]);
            queue[rear++] = temp->right;
        }
    }
    return root;
}
int countNodes(struct Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
bool isComplete(struct Node* root, int index, int totalNodes) {
    if (!root) return true;
    if (index >= totalNodes)
        return false;
    return isComplete(root->left, 2 * index + 1, totalNodes) &&
           isComplete(root->right, 2 * index + 2, totalNodes);
}
bool isMinHeap(struct Node* root) {
    if (!root->left && !root->right)
        return true;
    if (!root->right) {
        return (root->data <= root->left->data) &&
               isMinHeap(root->left);
    }
    if (root->data <= root->left->data &&
        root->data <= root->right->data) {
        return isMinHeap(root->left) &&
               isMinHeap(root->right);
    }
    return false;
}
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    struct Node* root = buildTree(arr, n);
    int totalNodes = countNodes(root);
    if (isComplete(root, 0, totalNodes) && isMinHeap(root))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}