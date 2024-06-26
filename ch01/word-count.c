#include <stdio.h>

#define IN   1  // Inside a word
#define OUT  0  // Outside a word

int main(void) {
    int state = OUT;
    int nl = 0;
    int nw = 0;
    int nc = 0;
    int ch = getchar();
    while (ch != EOF) {
        nc += 1;
        if (ch == '\n') {
            nl += 1;
        }
        if (ch == ' ' || ch == '\n' || ch == '\t') {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            nw += 1;
        }
        ch = getchar();
    }

    printf("%d %d %d\n", nl, nw, nc);

    return 0;
}
