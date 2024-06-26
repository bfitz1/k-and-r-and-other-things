#include <stdio.h>

#define TAB '\t'
#define BACKSPACE '\b'
#define BACKSLASH '\\'

int main(void) {
    int ch = getchar();
    while (ch != EOF) {
        if (ch == TAB) {
            putchar('\\');
            putchar('t');
        } else if (ch == BACKSPACE) {
            putchar('\\');
            putchar('b');
        } else if (ch == BACKSLASH) {
            putchar('\\');
            putchar('\\');
        } else {
            putchar(ch);
        }
        ch = getchar();
    }
        
    return 0;
}
