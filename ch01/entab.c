#include <stdio.h>

#define TABSTOP 4

int collapse_spaces(int col);

int main(void) {
    int col = 0;
    int ch = getchar();
    while (ch != EOF) {
        if (ch == ' ') {
            ungetc(ch, stdin);
            col = collapse_spaces(col);
        } else if (ch == '\n') {
            putchar('\n');
            col = 0;
        } else {
            putchar(ch);
            col += 1;
        }
        ch = getchar();
    }
    return 0;
}

int collapse_spaces(int col) {
    int i = 0;
    int ch = getchar();
    while (ch == ' ') {
        i += 1;
        ch = getchar();
    } 
    // Put the non-space character back
    ungetc(ch, stdin);
    
    if (i < TABSTOP) {
        // Just use spaces here; the logic to mix tabs and spaces gets squirrelly
        while (i > 0) {
            putchar(' ');
            col += 1;
            i -= 1;
        }
    } else {
        // Align the current column position with the next tab stop
        while (col % TABSTOP != 0) {
            putchar(' ');
            col += 1;
            i -= 1;
        }
        // Fill the rest of the spaces with tabs
        while (i > 0) {
            putchar('\t');
            col += TABSTOP;
            i -= TABSTOP;
        }
    }

    return col;
}
