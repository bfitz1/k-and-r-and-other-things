#include <stdio.h>

int main(void) {
    long nc = 0;
    while (getchar() != EOF) {
        nc += 1;
    }
    printf("%ld\n", nc);

    return 0;
}
