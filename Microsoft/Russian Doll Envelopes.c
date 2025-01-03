#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Comparator function for sorting the envelopes
int compare(const void* a, const void* b) {
    int* envA = *(int**)a;
    int* envB = *(int**)b;
    if (envA[0] != envB[0]) {
        return envA[0] - envB[0]; // Sort by width in ascending order
    }
    return envB[1] - envA[1]; // If widths are equal, sort by height in descending order
}

// Binary search function to find the position to replace or insert height
int binarySearch(int* dp, int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (dp[mid] >= target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int maxEnvelopes(int** envelopes, int envelopesSize, int* envelopesColSize) {
    // Sort the envelopes using the custom comparator
    qsort(envelopes, envelopesSize, sizeof(int*), compare);

    // Array to store the heights for the LIS
    int* dp = (int*)malloc(envelopesSize * sizeof(int));
    int length = 0;

    // Compute the LIS on heights
    for (int i = 0; i < envelopesSize; i++) {
        int height = envelopes[i][1];
        int pos = binarySearch(dp, length, height);
        if (pos == length) {
            dp[length++] = height; // Append to the sequence
        } else {
            dp[pos] = height; // Replace the element
        }
    }

    free(dp);
    return length;
}
