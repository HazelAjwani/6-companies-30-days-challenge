#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void wiggleSort(int* nums, int numsSize) {
    if (numsSize <= 1) return;

    // Sort the array
    qsort(nums, numsSize, sizeof(int), compare);

    // Create a temporary array to hold the sorted values
    int *temp = (int *)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        temp[i] = nums[i];
    }

    int mid = (numsSize - 1) / 2;
    int j = mid;          // Pointer for the smaller half
    int k = numsSize - 1; // Pointer for the larger half

    // Place elements in wiggle order
    for (int i = 0; i < numsSize; i++) {
        if (i % 2 == 0) {
            nums[i] = temp[j--]; // Fill even indices with smaller half
        } else {
            nums[i] = temp[k--]; // Fill odd indices with larger half
        }
    }

    // Free the temporary array
    free(temp);
}

// Helper function to print the array
void printArray(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}
