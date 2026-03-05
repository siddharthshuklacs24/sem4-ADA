#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Helper function for qsort to sort characters
int compareChars(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}

char* orderlyQueue(char* s, int k) {
    int n = strlen(s);

    // CASE 1: If k > 1, we can sort the string entirely.
    if (k > 1) {
        qsort(s, n, sizeof(char), compareChars);
        return s;
    } 

    // CASE 2: If k = 1, we find the smallest cyclic rotation.
    // We create a buffer to store the best rotation found so far.
    char* smallest = (char*)malloc((n + 1) * sizeof(char));
    char* current = (char*)malloc((n + 1) * sizeof(char));
    strcpy(smallest, s);
    strcpy(current, s);

    for (int i = 0; i < n; i++) {
        // Rotate the string by 1 position
        char first = current[0];
        memmove(current, current + 1, n - 1);
        current[n - 1] = first;
        current[n] = '\0';

        // Compare with the smallest found so far
        if (strcmp(current, smallest) < 0) {
            strcpy(smallest, current);
        }
    }

    free(current);
    return smallest;
}
