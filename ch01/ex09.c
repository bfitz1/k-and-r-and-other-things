#include <stdio.h>

int main(void) {
    char skip_blanks = 0;
    int ch = getchar();
    while (ch != EOF) {
        if (ch != ' ') {
            putchar(ch);
            skip_blanks = 0;
        } else if (!skip_blanks) {
            putchar(ch);
            skip_blanks = 1;
        }
        ch = getchar();
    }
    return 0;
}
