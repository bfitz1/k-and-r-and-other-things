#include <stdio.h>

#define MAX_LINE_LENGTH 256

size_t str_getline(char buf[], size_t buflen);
void reverse(char s[]);

int main(void) {
    char buf[MAX_LINE_LENGTH] = {0};
    size_t len = str_getline(buf, MAX_LINE_LENGTH);
    while (len > 0) {
        reverse(buf);
        len = str_getline(buf, MAX_LINE_LENGTH);
    }
    printf("\n");
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

void reverse(char s[]) {
    int i = 0;
    while (s[i] != 0 && s[i] != '\n') {
        i += 1;
    }
    // Move backward one since s[i] is \0 or \n
    i -= 1;
    while (i >= 0) {
        printf("%c", s[i]);
        i -= 1;
    }
    printf("\n");
}
