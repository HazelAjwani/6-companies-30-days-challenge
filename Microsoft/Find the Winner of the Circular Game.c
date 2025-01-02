#include <stdio.h>

int findTheWinner(int n, int k) {
    int winner = 0; // Initial winner position for 1 person (base case)
    for (int i = 2; i <= n; i++) {
        winner = (winner + k) % i; // Update winner position
    }
    return winner + 1; // Convert 0-based index to 1-based
}
