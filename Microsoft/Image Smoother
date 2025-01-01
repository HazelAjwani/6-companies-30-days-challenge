#include <stdlib.h>
#include <stdio.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** imageSmoother(int** img, int imgSize, int* imgColSize, int* returnSize, int** returnColumnSizes) {
    int rows = imgSize;
    int cols = *imgColSize;

    // Allocate memory for the result matrix
    int** result = (int**)malloc(rows * sizeof(int*));
    *returnColumnSizes = (int*)malloc(rows * sizeof(int));
    *returnSize = rows;

    for (int i = 0; i < rows; i++) {
        result[i] = (int*)malloc(cols * sizeof(int));
        (*returnColumnSizes)[i] = cols;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int sum = 0, count = 0;
            
            // Add the current cell
            sum += img[i][j];
            count++;

            // Add the neighbors
            if (i - 1 >= 0) {
                sum += img[i - 1][j];
                count++;
                if (j - 1 >= 0) {
                    sum += img[i - 1][j - 1];
                    count++;
                }
                if (j + 1 < cols) {
                    sum += img[i - 1][j + 1];
                    count++;
                }
            }
            if (i + 1 < rows) {
                sum += img[i + 1][j];
                count++;
                if (j - 1 >= 0) {
                    sum += img[i + 1][j - 1];
                    count++;
                }
                if (j + 1 < cols) {
                    sum += img[i + 1][j + 1];
                    count++;
                }
            }
            if (j - 1 >= 0) {
                sum += img[i][j - 1];
                count++;
            }
            if (j + 1 < cols) {
                sum += img[i][j + 1];
                count++;
            }

            // Compute the smoothed value
            result[i][j] = sum / count;
        }
    }

    return result;
}
