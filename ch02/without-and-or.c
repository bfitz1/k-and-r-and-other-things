#include <stdio.h>

#define MAX_LINE_LENGTH 1000

int str_getline(char buf[], int lim);

int main(void) {
    char line[MAX_LINE_LENGTH] = {0};
    str_getline(line, MAX_LINE_LENGTH);
    printf("%s\n", line);

    return 0;
}

// Implement a getline function without using logical and (&&) nor logical or (||).
// Functionally we're just breaking the loop when those conditions are encountered.
int str_getline(char buf[], int lim) {
    int i;
    int ch;
    for (i = 0; i < lim-1; ++i) {
        ch = getchar();
        if (ch == '\n') {
            break;
        }
        if (ch == EOF) {
            break;
        }
        buf[i] = ch;
    }
    buf[i] = '\0';
    return i;
}
