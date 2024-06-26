#include <stdio.h>

#define OUT 0
#define IN  1
#define MAX_WORD_LENGTH 16

int main(void) {
    long word_lengths[MAX_WORD_LENGTH] = {0};
    int state = OUT;
    long length = 0;
    int ch = getchar();
    while (ch != EOF) {
        if (ch == ' ' || ch == '\t' || ch == '\n') {
            if (state == IN) {
                // Avoid out-of-bounds indexing errors
                int index = length > 16 ? 16 : length; 
                word_lengths[index-1] += 1;
                length = 0;
            }
            state = OUT;
        } else {
            length += 1;
            state = IN;
        }
        ch = getchar();
    }

#ifdef HORIZONTAL
    // Horizontal histogram
    for (int i = 0; i < MAX_WORD_LENGTH; i += 1) {
        printf("%2d: ", i+1);
        for (int j = 0; j < word_lengths[i]; j += 1) {
            printf("*");
        }
        printf("\n");
    }
#endif

#ifndef HORIZONTAL
    // Vertical histogram - a little more involved
    // Find the max 
    long max_length = 0;
    for (int i = 0; i < MAX_WORD_LENGTH; i += 1) {
        if (word_lengths[i] > max_length) {
            max_length = word_lengths[i];
        }
    }

    // Construct a difference array I guess?
    long difference[MAX_WORD_LENGTH] = {0};
    for (int i = 0; i < MAX_WORD_LENGTH; i += 1) {
        difference[i] = word_lengths[i] - max_length;
    }

    // Now we know how many rows the histogram will take up
    for (long r = 0; r < max_length; r += 1) {
        for (int i = 0; i < MAX_WORD_LENGTH; i += 1) {
            if (difference[i] < 0) {
                printf("   ");
            } else {
                printf("  *");
            }
            difference[i] += 1;
        }
        printf("\n");
    }
    for (int i = 0; i < MAX_WORD_LENGTH; i += 1) {
        printf("---");
    }
    printf("\n");
    for (int i = 0; i < MAX_WORD_LENGTH; i += 1) {
        printf("%3d", i+1);
    }
    printf("\n");
#endif

    return 0;
}
