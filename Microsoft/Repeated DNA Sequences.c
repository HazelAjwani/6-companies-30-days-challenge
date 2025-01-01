#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

// Function to find repeated DNA sequences
char** findRepeatedDnaSequences(char* s, int* returnSize) {
    int len = strlen(s);
    *returnSize = 0;

    // If the string length is less than 10, no sequences are possible
    if (len < 10) {
        return NULL;
    }

    // Hash set to store sequences we have seen
    int seen[1 << 20] = {0}; // Use a large enough array for hash values
    int added[1 << 20] = {0}; // To track sequences added to the result

    // Allocate memory for the result
    char** result = (char**)malloc(MAX_LENGTH * sizeof(char*));

    for (int i = 0; i <= len - 10; i++) {
        char sequence[11];
        strncpy(sequence, s + i, 10);
        sequence[10] = '\0'; // Null-terminate the string

        unsigned long hash = 0;
        for (int j = 0; j < 10; j++) {
            hash = (hash << 2) | (sequence[j] == 'A' ? 0 : (sequence[j] == 'C' ? 1 : (sequence[j] == 'G' ? 2 : 3)));
        }

        if (seen[hash] && !added[hash]) {
            result[*returnSize] = (char*)malloc(11 * sizeof(char));
            strcpy(result[*returnSize], sequence);
            (*returnSize)++;
            added[hash] = 1;
        } else {
            seen[hash] = 1;
        }
    }

    return result;
}

// Helper function to free the result
void freeResult(char** result, int size) {
    for (int i = 0; i < size; i++) {
        free(result[i]);
    }
    free(result);
}
