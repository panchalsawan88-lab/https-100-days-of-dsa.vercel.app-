/*Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

Input Format
An integer array arr[].

Output Format
Print the length of the longest subarray with sum equal to zero.

Sample Input
15 -2 2 -8 1 7 10 23

Sample Output
5

Explanation
The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.*/

#include <stdio.h>

#define MAX 1000

int main() {
    int n;
    scanf("%d", &n);
    int arr[MAX];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int prefixSum[MAX];
    int maxLen = 0;
    prefixSum[0] = arr[0];
    for(int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
    for(int i = 0; i < n; i++) {
        if(prefixSum[i] == 0) {
            maxLen = i + 1;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(prefixSum[i] == prefixSum[j]) {
                int length = j - i;
                if(length > maxLen) {
                    maxLen = length;
                }
            }
        }
    }
    printf("%d\n", maxLen);
    return 0;
}