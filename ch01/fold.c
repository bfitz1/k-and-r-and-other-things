#include <stdio.h>

#define LINE_LENGTH 72

int main(void) {
    int col = 0;
    int ch = getchar();
    while (ch != EOF) {
        // Simplest version: just wrap at LINE_LENGTH-1 regardless of what's there
        while (ch != EOF && col < LINE_LENGTH-1) {
            putchar(ch);
            col += 1;
            ch = getchar();
        }
        if (ch != EOF) {
            putchar('\n');
            col = 0;
        }
    }
    return 0;
}
