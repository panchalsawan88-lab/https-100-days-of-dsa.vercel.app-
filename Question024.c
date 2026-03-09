/*Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated

Example:
Input:
5
10 20 30 40 50
30

Output:
10 20 40 50

Explanation:
Traverse list, find first node with key, remove it by adjusting previous node's next pointer.*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}
struct Node* deleteFirstOccurrence(struct Node* head, int key) {
    if (head == NULL)
        return head;
    if (head->data == key) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct Node* prev = head;
    struct Node* curr = head->next;
    while (curr != NULL) {
        if (curr->data == key) {
            prev->next = curr->next;
            free(curr);
            return head;   
        }
        prev = curr;
        curr = curr->next;
    }
    return head;  
}
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}
int main() {
    int n, key;
    scanf("%d", &n);
    struct Node* head = createList(n);
    scanf("%d", &key);
    head = deleteFirstOccurrence(head, key);
    printList(head);
    return 0;
}