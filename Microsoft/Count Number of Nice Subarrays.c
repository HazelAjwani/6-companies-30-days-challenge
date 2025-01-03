#include <stdio.h>
#include <stdlib.h>

int numberOfSubarrays(int* nums, int numsSize, int k) {
    int* count = (int*)calloc(numsSize + 1, sizeof(int));
    int sum = 0, ans = 0;

    // Initialize with count[0] = 1 to handle the subarrays starting from the first element.
    count[0] = 1;

    for (int i = 0; i < numsSize; i++) {
        // Increment sum by 1 if nums[i] is odd, otherwise leave it unchanged.
        sum += nums[i] % 2;

        // If (sum - k) exists, add its count to the answer.
        if (sum >= k) {
            ans += count[sum - k];
        }

        // Increment the count for the current sum.
        count[sum]++;
    }

    // Free the dynamically allocated memory.
    free(count);

    return ans;
}
