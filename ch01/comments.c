#include <stdio.h>

#define MAX_BUF_SIZE 128

void write_whitespace(char buf[], size_t buflen);
void read_quoted_string();
void remove_winged_comment();
void remove_wand_comment();

/* Hey, this comment is here
 * just to test if my comment-deleting
 * code works
 */ 
int main(void) {
    char buf[MAX_BUF_SIZE] = {0};
    size_t buflen = 0;

    int ch = getchar();
    while (ch != EOF) {
        int peek = getchar();
        ungetc(peek, stdin);

        // Buffer spaces and tabs in case we need to delete comment lines
        if (ch == ' ' || ch == '\t') {
            buf[buflen] = ch;
            buflen += 1;
        } else if (ch != '\'' && peek == '"') {
            write_whitespace(buf, buflen);
            buflen = 0;
            // Print unconditionally up until a matching quotation mark
            putchar(ch);
            putchar(peek);
            getchar();
            read_quoted_string();
        } else if (ch == '/' && peek == '/') {
            buflen = 0;
            // Ignore the remainder of the line
            getchar();
            remove_winged_comment();
        } else if (ch == '/' && peek == '*') {
            buflen = 0;
            // Ignore everything up until a closing wand
            getchar();
            remove_wand_comment();
        } else {
            write_whitespace(buf, buflen);
            buflen = 0;
            putchar(ch);
        }
        ch = getchar();
    }
    return 0;
}

void write_whitespace(char buf[], size_t buflen) {
    size_t i = 0;
    while (i < buflen) {
        putchar(buf[i]);
        i += 1;
    }
}

void read_quoted_string() {
    int ch = getchar();
    while (ch != EOF && ch != '"') {
        putchar(ch);
        ch = getchar();
    }
    if (ch == '"') {
        putchar('"');
    }
}

void remove_winged_comment() {
    int ch = getchar();
    while (ch != EOF && ch != '\n') {
        ch = getchar();
    }
}

void remove_wand_comment() {
    int ch = getchar();
    while (ch != EOF) {
        int peek = getchar();
        ungetc(peek, stdin);
        if (ch == '*' && peek == '/') {
            getchar();
            break;
        }
        ch = getchar();
    }
}
