#include <stdio.h>

static char *reverse_rec(char buf[], char ptr[]) {
    if (ptr[0] == '\0') {
        return buf;
    }

    char ch = ptr[0];
    if (ptr[1] != '\0') {
        buf = reverse_rec(buf, ptr + 1);
    }
    buf[0] = ch;
    buf[1] = '\0';

    return buf + 1;
}

void reverse(char buf[]) {
    reverse_rec(buf, buf);
}
