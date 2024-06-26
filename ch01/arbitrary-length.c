#include <stdio.h>

#define MAX_LINE_LENGTH 64

long long str_getline(char *buf, long long buflen);
void str_copy(char *to, char *from);

int main(void) {
    char buf[MAX_LINE_LENGTH] = {0};
    char longest[MAX_LINE_LENGTH] = {0};
    long long max = 0;

    long long length = str_getline(buf, MAX_LINE_LENGTH);
    while (length > 0) {
        if (length > max) {
            max = length;
            str_copy(longest, buf);
        }
        length = str_getline(buf, MAX_LINE_LENGTH);
    }

    printf("(%lld chars): %s", max, longest);
    if (max > MAX_LINE_LENGTH) {
        printf("...\n");
    } else {
        printf("\n");
    }

    return 0;
}

long long str_getline(char *buf, long long buflen) {
    long long i = 0;
    int ch = getchar();
    while (i < buflen-1 && ch != '\n' && ch != EOF) {
        buf[i] = ch;
        i += 1;
        ch = getchar();
    }
    buf[i] = 0;

    // Did we actually hit the end of the line/file?
    while (ch != '\n' && ch != EOF) {
        i += 1;
        ch = getchar();
    }
    if (ch == '\n') {
        i += 1;
    }
    return i;
}

// Assumes that the sequence being read from is terminated by a null byte. So, uh, be careful!
void str_copy(char *to, char *from) {
    long long i = 0;
    while (from[i] != 0) {
        to[i] = from[i];
        i += 1;
    }
    to[i] = 0;
}
