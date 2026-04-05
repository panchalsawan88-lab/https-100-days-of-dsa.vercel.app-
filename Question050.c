/*Problem: BST Search

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/

#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    if (root == NULL) return createNode(val);

    if (val < root->val)
        root->left = insertIntoBST(root->left, val);
    else
        root->right = insertIntoBST(root->right, val);

    return root;
}
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    while (root != NULL) {
        if (root->val == val)
            return root;
        else if (val < root->val)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}
int main() {
    struct TreeNode* root = NULL;
    int n, val, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insertIntoBST(root, val);
    }

    printf("Enter value to search: ");
    scanf("%d", &key);

    struct TreeNode* result = searchBST(root, key);

    if (result != NULL)
        printf("Value %d found in BST.\n", key);
    else
        printf("Value %d NOT found in BST.\n", key);

    return 0;
}