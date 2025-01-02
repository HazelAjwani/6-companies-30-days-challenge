#include <stdio.h>
#include <stdbool.h>

// Function to check if a segment of the array is strictly increasing
bool isStrictlyIncreasing(int nums[], int start, int end) {
    for (int i = start; i < end - 1; i++) {
        if (nums[i] >= nums[i + 1]) {
            return false;
        }
    }
    return true;
}

int incremovableSubarrayCount(int nums[], int n) {
    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // Check if removing the subarray nums[i...j] makes the remaining parts strictly increasing
            bool leftIncreasing = (i == 0) || isStrictlyIncreasing(nums, 0, i);
            bool rightIncreasing = (j == n - 1) || isStrictlyIncreasing(nums, j + 1, n);

            // Check if the boundary elements (nums[i-1] and nums[j+1]) maintain the strictly increasing condition
            bool boundaryCondition = (i == 0 || j == n - 1 || nums[i - 1] < nums[j + 1]);

            if (leftIncreasing && rightIncreasing && boundaryCondition) {
                ans++;
            }
        }
    }

    return ans;
}
