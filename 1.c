#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[100]; // assuming max size 100 for simplicity
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int pos, x;
    scanf("%d", &pos); // 1-based position
    scanf("%d", &x);

    // Shift elements to the right from the end to pos-1
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert x at position pos-1 (0-based index)
    arr[pos - 1] = x;
    n++; // array size increases by 1

    // Print updated array
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");

    return 0;
}
