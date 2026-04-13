#include <stdio.h>
#include <string.h>

char firstRepeatedChar(const char *s) {
    int seen[26] = {0};  // Array to track occurrences of each character

    for (int i = 0; s[i] != '\0'; i++) {
        int idx = s[i] - 'a';   // Map character to index (0–25)
        if (seen[idx] == 1) {
            return s[i];        // Found the first repeated character
        }
        seen[idx] = 1;          // Mark character as seen
    }
    return -1;  // No repeated character found
}

int main() {
    char s[100];
    scanf("%s", s);

    char result = firstRepeatedChar(s);
    if (result == -1)
        printf("-1\n");
    else
        printf("%c\n", result);

    return 0;
}

