#include <stdio.h>

int main(void) {
    int ndigit[10] = {0};
    int nwhite = 0;
    int nother = 0;

    int ch = getchar();
    while (ch != EOF) {
        if (ch >= '0' && ch <= '9') {
            ndigit[ch - '0'] += 1;
        } else if (ch == ' ' || ch == '\n' || ch == '\t') {
            nwhite += 1;
        } else {
            nother += 1;
        }
        ch = getchar();
    }

    printf("digits =");
    for (int i = 0; i < 10; i += 1) {
        printf(" %d", ndigit[i]);
    }
    printf(", white space = %d, other = %d\n", nwhite, nother);

    return 0;
}
