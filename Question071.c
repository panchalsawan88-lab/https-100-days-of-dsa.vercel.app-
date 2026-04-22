/*Problem Statement
Implement a hash table using quadratic probing with formula:

h(k, i) = (h(k) + i*i) % m

Input Format
Same as previous.

Output Format
Result of SEARCH operations.

Sample Input
7
4
INSERT 49
INSERT 56
SEARCH 49
SEARCH 15

Sample Output
FOUND
NOT FOUND

Explanation
Collisions resolved using i² jumps.*/

#include <stdio.h>
#include <string.h>
#define SIZE 100
int table[SIZE];
void init(int m) {
    for (int i = 0; i < m; i++) {
        table[i] = -1;
    }
}
void insert(int key, int m) {
    int h = key % m;
    for (int i = 0; i < m; i++) {
        int index = (h + i * i) % m;
        if (table[index] == -1) {
            table[index] = key;
            return;
        }
    }
}
void search(int key, int m) {
    int h = key % m;
    for (int i = 0; i < m; i++) {
        int index = (h + i * i) % m;
        if (table[index] == -1) {
            printf("NOT FOUND\n");
            return;
        }
        if (table[index] == key) {
            printf("FOUND\n");
            return;
        }
    }
    printf("NOT FOUND\n");
}
int main() {
    int m, n;
    scanf("%d", &m);
    scanf("%d", &n);
    init(m);
    char op[10];
    int key;
    for (int i = 0; i < n; i++) {
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key, m);
        } else if (strcmp(op, "SEARCH") == 0) {
            search(key, m);
        }
    }
    return 0;
}