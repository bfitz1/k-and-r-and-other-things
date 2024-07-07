#include <stdio.h>

void itoa(int n, char s[], int w);

int main(void) {
    int n = 12345;
    char s[16] = {0};
    int w = 8;
    itoa(n, s, w);

    return 0;
}

void itoa(int n, char s[], int w) {
    int offset = 0;
    int remain = n;
    do {
        offset += 1;
        remain /= 10;
    } while (remain != 0);

    int sign = 1;
    if (n < 0) {
        sign = -1;
        offset += 1;
    }

    if (offset < w) {
        offset = w;
    }

    int i = 0;
    remain = n;
    do {
        s[offset-1-i] = '0' + sign * (remain % (sign * 10));
        i += 1;
        remain /= 10;
    } while (remain != 0);

    if (sign == -1) {
        while (i < offset-1) {
            s[offset-1-i] = '0';
            i += 1;
        }
        s[offset-1-i] = '-';
    } else {
        while (i < offset) {
            s[offset-1-i] = '0';
            i += 1;
        }
    }

    s[offset] = '\0';
}
