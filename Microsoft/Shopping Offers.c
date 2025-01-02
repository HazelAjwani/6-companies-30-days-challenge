#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

// Memoization entry
typedef struct {
    int needsHash;
    int cost;
} MemoEntry;

#define MAX_NEEDS 6
#define HASH_TABLE_SIZE 10007

MemoEntry memo[HASH_TABLE_SIZE];
int memoSize = 0;

// Compute hash for needs array
int computeHash(int *needs, int needsSize) {
    int hash = 0;
    for (int i = 0; i < needsSize; i++) {
        hash = (hash * 31 + needs[i]) % HASH_TABLE_SIZE;
    }
    return hash;
}

// Check if a state is in the memo
int findMemo(int *needs, int needsSize) {
    int hash = computeHash(needs, needsSize);
    for (int i = 0; i < memoSize; i++) {
        if (memo[i].needsHash == hash) {
            return memo[i].cost;
        }
    }
    return -1;
}

// Add a state to the memo
void addMemo(int *needs, int needsSize, int cost) {
    int hash = computeHash(needs, needsSize);
    memo[memoSize].needsHash = hash;
    memo[memoSize].cost = cost;
    memoSize++;
}

int shoppingOffers(int *price, int priceSize, int **special, int specialSize, int *specialColSize, int *needs, int needsSize) {
    // Calculate the direct cost of buying all items without special offers
    int directCost = 0;
    for (int i = 0; i < needsSize; i++) {
        directCost += price[i] * needs[i];
    }

    // Check if result is already memoized
    int memoResult = findMemo(needs, needsSize);
    if (memoResult != -1) {
        return memoResult;
    }

    int minCost = directCost;

    // Try all special offers
    for (int i = 0; i < specialSize; i++) {
        bool isValid = true;

        // Check if the special offer can be applied
        for (int j = 0; j < needsSize; j++) {
            if (needs[j] < special[i][j]) {
                isValid = false;
                break;
            }
        }

        if (isValid) {
            // Apply the offer
            for (int j = 0; j < needsSize; j++) {
                needs[j] -= special[i][j];
            }

            // Recur to calculate the cost after applying the offer
            int offerCost = special[i][needsSize] + shoppingOffers(price, priceSize, special, specialSize, specialColSize, needs, needsSize);
            if (offerCost < minCost) {
                minCost = offerCost;
            }

            // Revert the applied offer
            for (int j = 0; j < needsSize; j++) {
                needs[j] += special[i][j];
            }
        }
    }

    // Memoize and return the result
    addMemo(needs, needsSize, minCost);
    return minCost;
}

