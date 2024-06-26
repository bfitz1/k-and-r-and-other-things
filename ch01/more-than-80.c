#include <stdio.h>

#define MIN_LINE_LENGTH 80
#define MAX_LINE_LENGTH 256

size_t str_getline(FILE *f, char *buf, size_t buflen);
void str_copy(char *to, char *from);

// Print all lines which are at least 80 characters long. Not sure if any of these
// are actually that long though!
int main(void) {
    char buf[MAX_LINE_LENGTH] = {0};

    size_t len = str_getline(stdin, buf, MAX_LINE_LENGTH);
    while (len > 0) {
        if (len >= MIN_LINE_LENGTH) {
            printf("%s\n", buf);
        }
        len = str_getline(stdin, buf, MAX_LINE_LENGTH);
    }
       
    return 0;
}

size_t str_getline(FILE *f, char *buf, size_t buflen) {
    size_t len = 0;
    int ch = fgetc(f);
    while (len < buflen-1 && ch != '\n' && ch != EOF) {
        buf[len] = ch;
        len += 1;
        ch = fgetc(f);
    }
    buf[len] = 0;

    if (ch == '\n') {
        len += 1;
    }

    return len;
}

void str_copy(char *to, char *from) {
    size_t i = 0;
    while (from[i] != 0) {
        to[i] = from[i];
        i += 1;
    }
    to[i] = 0;
}
