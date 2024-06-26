#include <stdio.h>

#define MAX_LINE_LENGTH 256

size_t str_getline(char buf[], size_t buflen);
size_t str_trim(char buf[], size_t buflen);
void str_copy(char to[], char from[]);

int main(void) {
    char buf[MAX_LINE_LENGTH] = {0};
    size_t len = str_getline(buf, MAX_LINE_LENGTH);
    while (len > 0) {
        if (str_trim(buf, len) > 0) {
            printf("%s\n", buf);
        }
        len = str_getline(buf, MAX_LINE_LENGTH);
    }

    return 0;
}

size_t str_getline(char buf[], size_t buflen) {
    size_t i = 0;
    int ch = getchar();
    while (i < buflen-1 && ch != '\n' && ch != EOF) {
        buf[i] = ch;
        i += 1;
        ch = getchar();
    }

    if (i < buflen-1 && ch == '\n') {
        buf[i] = '\n';
        i += 1;
    }

    buf[i] = 0;
    return i;
}

size_t str_trim(char buf[], size_t end) {
    size_t i = end - 1;
    while (i >= 0 && (buf[i] == ' ' || buf[i] == '\t' || buf[i] == '\n')) {
        buf[i] = 0;
        i -= 1;
    }

    return i + 1;
}

void str_copy(char to[], char from[]) {
    size_t i = 0;
    while (from[i] != 0) {
        to[i] = from[i];
        i += 1;
    }
    to[i] = 0;
}
