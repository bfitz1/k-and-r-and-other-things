#include <stdio.h>
#define MAXLINE 1000

int readline(char line[], int maxline);
void copy(char to[], char from[]);

int main(void) {
    char line[MAXLINE] = {0};
    char longest[MAXLINE] = {0};

    int max = 0;
    int len = readline(line, MAXLINE);
    while (len > 0) {
        if (len > max) {
            copy(longest, line);
            max = len;
        }
        len = readline(line, MAXLINE);
    }
    if (max > 0) {
        printf("%s", longest);
    }

    return 0;
}

int readline(char s[], int lim) {
    int i = 0;
    int ch = getchar();
    while (i < lim-1 && ch != EOF && ch != '\n') {
        s[i] = ch;
        ch = getchar();
        i += 1;
    }
    if (ch == '\n') {
        s[i] = ch;
        i += 1;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[]) {
    int i = 0;
    to[i] = from[i];
    while (to[i] != '\0') {
        i += 1;
        to[i] = from[i];
    }
}
