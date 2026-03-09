/*Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k

Output:
- Print the linked list elements after rotation, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
40 50 10 20 30

Explanation:
Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
int main() {
    int n;
    scanf("%d", &n);
    if (n <= 0) return 0;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    int k;
    scanf("%d", &k);
    if (k == 0 || head == NULL)
    {
        temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        return 0;
    }
    int length = 1;
    struct Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
        length++;
    }
    k = k % length;
    if (k == 0) {
        temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        return 0;
    }
    tail->next = head;
    int steps = length - k;
    struct Node* newTail = head;
    for (int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }
    head = newTail->next;
    newTail->next = NULL;
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return 0;
}