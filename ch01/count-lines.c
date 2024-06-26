#include <stdio.h>

int main(void) {
    int nl = 0;
    int c = getchar();
    while (c != EOF) {
        if (c == '\n') {
            nl += 1;
        }
        c = getchar();
    }
    printf("%d\n", nl);

    return 0;
}
