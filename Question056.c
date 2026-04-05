/*Problem Statement:
Check whether a given binary tree is symmetric around its center.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print YES if symmetric, otherwise NO

Example:
Input:
7
1 2 2 3 4 4 3

Output:
YES

Explanation:
Left subtree is a mirror image of the right subtree.*/

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;
    struct Node* root = newNode(arr[0]);
    struct Node* queue[n];
    int front = 0, rear = 0;
    queue[rear++] = root;
    int i = 1;
    while (i < n) {
        struct Node* current = queue[front++];
        if (arr[i] != -1) {
            current->left = newNode(arr[i]);
            queue[rear++] = current->left;
        }
        i++;
        if (i < n && arr[i] != -1) {
            current->right = newNode(arr[i]);
            queue[rear++] = current->right;
        }
        i++;
    }
    return root;
}
int isMirror(struct Node* t1, struct Node* t2) {
    if (t1 == NULL && t2 == NULL)
        return 1;
    if (t1 == NULL || t2 == NULL)
        return 0;
    return (t1->data == t2->data &&
            isMirror(t1->left, t2->right) &&
            isMirror(t1->right, t2->left));
}
int isSymmetric(struct Node* root) {
    return isMirror(root, root);
}
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    struct Node* root = buildTree(arr, n);
    if (isSymmetric(root))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}