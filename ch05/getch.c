#include <stdio.h>

#define CHBUF_MAX 128

int chbuf[CHBUF_MAX] = {0};
int chptr = 0;

int getch(void) {
    if (chptr == 0) {
        return getchar();
    }

    int ch = chbuf[chptr-1];
    chptr -= 1;
    return ch;
}

void ungetch(int ch) {
    if (chptr == CHBUF_MAX) {
        printf("error: out of space on buffer");
        return;
    }

    chbuf[chptr] = ch;
    chptr += 1;
}
