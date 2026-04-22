/*Problem Statement
Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.

Input Format
First line contains an integer n representing number of votes.
Second line contains n space-separated strings representing candidate names.

Output Format
Print the name of the winning candidate followed by the number of votes received.

Sample Input
13
john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john

Sample Output
john 4

Explanation
Both john and johnny receive 4 votes, but john is lexicographically smaller, so john is declared the winner.*/

#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    char names[1000][50];  
    for(int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }
    int maxVotes = 0;
    char winner[50] = "";
    for(int i = 0; i < n; i++) {
        int count = 1;
        int alreadyCounted = 0;
        for(int k = 0; k < i; k++) {
            if(strcmp(names[i], names[k]) == 0) {
                alreadyCounted = 1;
                break;
            }
        }
        if(alreadyCounted) continue;
        for(int j = i + 1; j < n; j++) {
            if(strcmp(names[i], names[j]) == 0) {
                count++;
            }
        }
        if(count > maxVotes) {
            maxVotes = count;
            strcpy(winner, names[i]);
        }
        else if(count == maxVotes) {
            if(strcmp(names[i], winner) < 0) {
                strcpy(winner, names[i]);
            }
        }
    }
    printf("%s %d\n", winner, maxVotes);
    return 0;
}