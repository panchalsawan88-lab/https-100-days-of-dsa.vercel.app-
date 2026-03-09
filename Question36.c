/*Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
30 40 50 10 20

Explanation:
Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front.
Display remaining elements in correct order.*/

#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0;
int rear = -1;
int size = 0;

void enqueue(int value, int capacity)
{
    rear = (rear + 1) % capacity;
    queue[rear] = value;
    size++;
}

int dequeue(int capacity)
{
    int val = queue[front];
    front = (front + 1) % capacity;
    size--;
    return val;
}

int main()
{
    int n, m;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        enqueue(x, n);
    }

    scanf("%d", &m);

    for(int i = 0; i < m; i++)
    {
        int temp = dequeue(n);
        enqueue(temp, n);
    }

    for(int i = 0; i < size; i++)
    {
        printf("%d ", queue[(front + i) % n]);
    }

    return 0;
}

