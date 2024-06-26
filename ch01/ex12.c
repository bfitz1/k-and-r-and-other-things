#include <stdio.h>

#define IN   1
#define OUT  0

int main(void) {
    int state = OUT;
    int ch = getchar();
    while (ch != EOF) {
       if (ch == ' ' || ch == '\n' || ch == '\t') {
           if (state == IN) {
               putchar('\n');
           }
           state = OUT;
       } else {
           putchar(ch);
           state = IN;
       }
       ch = getchar();
    }
    return 0;
}
