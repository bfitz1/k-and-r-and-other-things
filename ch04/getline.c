#include <stdio.h>

int str_getline(char buf[], int bufsize) {
    int i = 0;
    int ch = getchar();
    while (ch != EOF && ch != '\n') {
        buf[i] = ch;
        i += 1;
        ch = getchar();
    }
    return i;
}
