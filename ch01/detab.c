#include <stdio.h>

#define TABSTOP 4

void expand_tab(int amount);

int main(void) {
    int col = 0;
    int ch = getchar();
    while (ch != EOF) {
        if (ch == '\t') {
            expand_tab(TABSTOP - (col % TABSTOP));
            col += TABSTOP - (col % TABSTOP);
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

void expand_tab(int amount) {
    while (amount > 0) {
        putchar(' ');
        amount -= 1;
    }
}
