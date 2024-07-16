#include <stdio.h>
#include <ctype.h>

#include "getch.h"

int getfloat(double *pn) {
    int ch = getch();
    while (isspace(ch)) {
        ch = getch();
    }

    if (!isdigit(ch) && ch != '.' && ch != '+' && ch != '-') {
        // Can't be a float
        ungetch(ch);
        return 0;
    }

    
    // Disallow "+", "-", ".", "+.", and "-." from being equivalent to
    // zero if not followed by a digit. This is kind of tricky actually,
    // and this approach feels like it could be improved.
    int sign = 1;
    if (ch == '+' || ch == '-') {
        sign = (ch == '-') ? -1 : 1;

        int signch = ch;
        ch = getch();
        if (ch == '.') {
            ch = getch();
            if (!isdigit(ch)) {
                ungetch(ch);
                ungetch('.');
                ungetch(signch);
                return 0;
            } else {
                ungetch(ch);
                ch = '.';
            }
        } else if (!isdigit(ch)) {
            ungetch(ch);
            ungetch(signch);
            return 0;
        }
    } else if (ch == '.') {
        ch = getch();
        if (!isdigit(ch)) {
            ungetch(ch);
            ungetch('.');
            return 0;
        } else {
            ungetch(ch);
            ch = '.';
        }
    }

    // I'm duplicating the book's approach more or less, but it feels
    // needless risky to mutate the pointer before we know the
    // operation is even valid.
    *pn = 0;
    while (isdigit(ch)) {
        *pn = (*pn * 10) + (ch - '0');
        ch = getch();
    }
    
    int power = 1;
    if (ch == '.') {
        ch = getch();
        while (isdigit(ch)) {
            power *= 10;
            *pn = (*pn * 10) + (ch - '0');
            ch = getch();
        }
    }
    *pn = sign * (*pn / power);

    if (ch != EOF) {
        ungetch(ch);
    }

    return ch;
}
