#include <stdio.h>
#include <string.h>

char* getHint(char* secret, char* guess) {
    int bulls = 0, cows = 0;
    int secret_count[10] = {0};
    int guess_count[10] = {0};
    int len = strlen(secret);
    
    for (int i = 0; i < len; i++) {
        if (secret[i] == guess[i]) {
            bulls++;
        } else {
            secret_count[secret[i] - '0']++;
            guess_count[guess[i] - '0']++;
        }
    }
    
    for (int i = 0; i < 10; i++) {
        cows += (secret_count[i] < guess_count[i]) ? secret_count[i] : guess_count[i];
    }
    
    static char result[20];
    snprintf(result, sizeof(result), "%dA%dB", bulls, cows);
    return result;
}
