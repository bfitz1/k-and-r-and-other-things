#include <stdio.h>

#define ALPHABET_LENGTH 95

int main(void) {
    long bins[ALPHABET_LENGTH] = {0};
    int ch = getchar();
    while (ch != EOF) {
        if ((ch == ' ' || ch == '\t' || ch == '\n')) {
            bins[0] += 1;
        } else {
            bins[ch - ' '] += 1;
        }
        ch = getchar();
    }

    for (int i = 0; i < ALPHABET_LENGTH; i += 1) {
        printf("'%c': ", i+32);
        for (int j = 0; j < bins[i]; j += 1) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
