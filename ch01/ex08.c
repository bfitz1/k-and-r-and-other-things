#include <stdio.h>

#define BLANK   ' '
#define TAB     '\t'
#define NEWLINE '\n'

int main(void) {
    long blank_count = 0;
    long tab_count = 0;
    long newline_count = 0;

    int ch = getchar();
    while (ch != EOF) {
        if (ch == BLANK) {
            blank_count += 1;
        } else if (ch == TAB) {
            tab_count += 1;
        } else if (ch == NEWLINE) {
            newline_count += 1;
        }
        ch = getchar();
    }

    printf("Blanks: %ld\n", blank_count);
    printf("Tabs: %ld\n", tab_count);
    printf("Newlines: %ld\n", newline_count);

    return 0;
}
