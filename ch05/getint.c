#include <stdio.h>
#include <ctype.h>

#include "getch.h"

// This function treats zero as an error? 
int getint(int *pn) {
    int c = getch();
    while (isspace(c)) {
        c = getch();
    }

    // Neither a number nor a end-of-file 
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }

    int sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        int d = c;
        c = getch();

        // Fix corner case where +/- not followed by a digit is still
        // a valid representation of zero.
        if (!isdigit(c)) {
            ungetch(c);
            ungetch(d);
            return 0;
        }
    }


    *pn = 0;
    while (isdigit(c)) {
        *pn *= 10;
        *pn += c - '0';
        c = getch();
    }
    *pn *= sign;

    if (c != EOF) {
        ungetch(c);
    }

    return c;
}
