#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LEN 100

// Structure to hold candidate name and vote count
typedef struct {
    char name[MAX_NAME_LEN];
    int count;
} Candidate;

// Function to find candidate index in array
int findCandidate(Candidate candidates[], int size, const char *name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(candidates[i].name, name) == 0) {
            return i;
        }
    }
    return -1; // not found
}

int main() {
    int n;
    scanf("%d", &n);

    Candidate candidates[n]; // array of candidates
    int candidateCount = 0;

    for (int i = 0; i < n; i++) {
        char vote[MAX_NAME_LEN];
        scanf("%s", vote);

        int idx = findCandidate(candidates, candidateCount, vote);
        if (idx != -1) {
            candidates[idx].count++;
        } else {
            strcpy(candidates[candidateCount].name, vote);
            candidates[candidateCount].count = 1;
            candidateCount++;
        }
    }

    // Find winner
    char winner[MAX_NAME_LEN];
    int maxVotes = -1;

    for (int i = 0; i < candidateCount; i++) {
        if (candidates[i].count > maxVotes) {
            maxVotes = candidates[i].count;
            strcpy(winner, candidates[i].name);
        } else if (candidates[i].count == maxVotes) {
            // Lexicographic tie-breaker
            if (strcmp(candidates[i].name, winner) < 0) {
                strcpy(winner, candidates[i].name);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}

